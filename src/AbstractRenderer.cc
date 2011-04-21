#include <GLUT/glut.h>
#include "AbstractRenderer.h"
#include "util.h"

//頂点座標
float vertices[][2] =
{
    {0, 400},
    {0, 0},
    {520, 0},
    {520,  400},
    // {-0.5f,  0.5f},
    // {-0.5f, -0.5f},
    // {0.5f, -0.5f},
    // {0.5f,  0.5f},
};
 
//uv(st)座標
float uvs[][2] =
{
   {0.f, 0.5f},
   {0.f, 0.f},
   {0.5f, 0.f},
   {0.5f, 0.5f},
};

unsigned int getClosestPowerOfTwo(unsigned int n)
{
	unsigned int m = 2;
	while(m < n) m<<=1;

	return m;
}

GLfloat texcoords[8] = {0.8, 0.8, 0.8, 0.0, 0.0, 0.0, 0.0, 0.8};

AbstractRenderer::AbstractRenderer(xn::Context *ctx, User* _user) : user(_user)
{
    depthGenerator = new xn::DepthGenerator;
    depthMeta = new xn::DepthMetaData;
    sceneMeta = new xn::SceneMetaData;

    CHECK_XN(ctx->FindExistingNode(XN_NODE_TYPE_DEPTH, *depthGenerator));

    depthGenerator->GetMetaData(*depthMeta);
    width  = depthMeta->XRes();
    height = depthMeta->YRes();
    texWidth = getClosestPowerOfTwo(width);
    texHeight = getClosestPowerOfTwo(height);

    depthBuf = new Vector[texWidth*texHeight];
    sceneBuf = new unsigned char[texWidth*texHeight*4];

    // texcoords[0] = (float)width/(float)texWidth;
    // texcoords[2] = (float)width/(float)texWidth;
    // texcoords[1] = (float)height/(float)texHeight;
    // texcoords[7] = (float)height/(float)texHeight;
    texcoords[0] = (float)texWidth;
    texcoords[2] = (float)texWidth;
    texcoords[1] = (float)texHeight;
    texcoords[7] = (float)texHeight;

    texID = 0;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glBindTexture(GL_TEXTURE_2D, 0);
}

AbstractRenderer::~AbstractRenderer(void)
{
    delete depthGenerator;
    delete depthMeta;
    delete [] depthBuf;
    delete [] sceneBuf;
}

void AbstractRenderer::draw(void)
{
    width  = depthMeta->XRes();
    height = depthMeta->YRes();

    depthGenerator->GetMetaData(*depthMeta);
    user->updatePixels(sceneMeta);

    const XnDepthPixel* depth = depthMeta->Data();
    const XnLabel* label = sceneMeta->Data();
    unsigned char* vp = sceneBuf; 

    for (int y = 0; y < depthMeta->YRes(); y++) {
        for (int x = 0; x < depthMeta->XRes(); x++, label++) {
            if (*label != 0) {
                vp[0] = 100;
                vp[1] = 255;
                vp[2] = 0;
                vp[3] = 100;
            } else {
                vp[0] = 255;
                vp[1] = 128;
                vp[2] = 210;
                vp[3] = 0xff;
            }
            vp += 4;
        }
        vp += (texWidth - depthMeta->XRes())*4;
    }

    glEnable(GL_TEXTURE_2D);
    //glColor4f(0.9,0.4,0.75,1);
    //glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, sceneBuf);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
   // //補完フィルタ設定。市松模様なのでnearestでおｋ
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    // GLfloat verts[8] = {width - 20, height - 20, width - 20, 0, 0, 0, 0, height - 20};
   glBegin(GL_QUADS);
   {
      glVertex2fv(vertices[0]); glTexCoord2fv(uvs[0]);
      glVertex2fv(vertices[1]); glTexCoord2fv(uvs[1]);
      glVertex2fv(vertices[2]); glTexCoord2fv(uvs[2]);
      glVertex2fv(vertices[3]); glTexCoord2fv(uvs[3]);
   }
 
   glEnd();

    // glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    // glVertexPointer(2, GL_FLOAT, 0, verts);
    // glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    // glBindTexture(GL_TEXTURE_2D, 0);        

    // //glDisableClientState(GL_VERTEX_ARRAY);
    // //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    //glDisable(GL_TEXTURE_2D);
}
