#include "UserFactory.h"

namespace ty {

const int UserFactory::MAX = 8;
UserContext* UserFactory::context = NULL;
User** UserFactory::list = NULL;

void UserFactory::setContext(xn::Context *ctx)
{
    context = new UserContext(ctx);
    list = new User*[MAX];
    
    for (int i = 0; i < UserFactory::MAX; i++) {
        list[i] = new User(context, i + 1);
    }
}

User* UserFactory::get(int userId)
{
    return list[userId - 1];
}

} // namespace ty
