#include <GLUT/glut.h>
#include "AbstractRenderer.h"
#include "util.h"

unsigned int getClosestPowerOfTwo(unsigned int n)
{
	unsigned int m = 2;
	while(m < n) m<<=1;

	return m;
}

GLfloat texcoords[8] = {0.8, 0.8, 0.8, 0.0, 0.0, 0.0, 0.0, 0.8};

AbstractRenderer::AbstractRenderer(ty::WorldContext *_ctx, ty::User* _user)
    : ctx(_ctx), user(_user)
{
    width     = ctx->depthWidth();
    height    = ctx->depthHeight();
    texWidth  = getClosestPowerOfTwo(width);
    texHeight = getClosestPowerOfTwo(height);
    
    sceneBuf = new unsigned char[texWidth*texHeight*4];

    texcoords[0] = (float)width/(float)texWidth;
    texcoords[2] = (float)width/(float)texWidth;
    texcoords[1] = (float)height/(float)texHeight;
    texcoords[7] = (float)height/(float)texHeight;

    texID = 0;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glBindTexture(GL_TEXTURE_2D, 0);
}

AbstractRenderer::~AbstractRenderer(void)
{
    delete [] sceneBuf;
}

void AbstractRenderer::draw(void)
{
    ctx->updateDepth();
    width  = ctx->depthWidth();
    height = ctx->depthHeight();

    const XnDepthPixel* depth = ctx->depthData();
    const XnLabel* label = user->scene()->Data();
    unsigned char* vp = sceneBuf; 

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++, label++) {
            if (*label != 0) {
                vp[0] = 128;
                vp[1] = 255;
                vp[2] = 128;
                vp[3] = 100;
            } else {
                vp[0] = 0;
                vp[1] = 0;
                vp[2] = 0;
                vp[3] = 0xaa;
            }
            vp += 4;
        }
        vp += (texWidth - width)*4;
    }

    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, sceneBuf);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    //補完フィルタ設定。市松模様なのでnearestでおｋ
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    GLfloat verts[8] = {width, height, width, 0, 0, 0, 0, height};
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glBindTexture(GL_TEXTURE_2D, 0);        

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
}
