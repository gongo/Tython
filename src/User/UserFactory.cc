#include <stdexcept>
#include "UserFactory.h"

namespace ty {

UserFactory::UserFactory(xn::Context& ctx)
{
    context = new UserContext(ctx);

    for (int i = 0; i < UserFactory::MAX; i++) {
        list[i] = new User(context, i + 1);
    }
}

UserFactory::~UserFactory(void)
{
    for (int i = 0; i < UserFactory::MAX; i++) {
        delete list[i];
    }

    delete context;
}

User* UserFactory::get(int userId)
{
    if (userId < 1 || MAX < userId) {
        throw std::out_of_range("\"userId\" must between 1 and UserFactory::MAX");
    }

    return list[userId - 1];
}

} // namespace ty
