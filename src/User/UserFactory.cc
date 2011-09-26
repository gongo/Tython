#include <stdexcept>
#include "UserFactory.h"

namespace ty {

UserContext* UserFactory::context = NULL;
User* UserFactory::list[UserFactory::MAX];

void UserFactory::setContext(xn::Context *ctx)
{
    if (context != NULL) {
        deleteContext();
    }
    
    context = new UserContext(ctx);
    
    for (int i = 0; i < UserFactory::MAX; i++) {
        list[i] = new User(context, i + 1);
    }
}

void UserFactory::deleteContext(void)
{
    for (int i = 0; i < UserFactory::MAX; i++) {
        delete list[i];
    }        

    delete context;
    context = NULL;    
}

User* UserFactory::get(int userId)
{
    if (MAX < userId || userId < 1) {
        throw std::out_of_range("\"userId\" must between 1 and UserFactory::MAX");
    }

    return list[userId - 1];
}

} // namespace ty
