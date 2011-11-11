// -*- C++ -*-

#ifndef _TYTHON_USER_FACTORY_H
#define _TYTHON_USER_FACTORY_H

#include "UserContext.h"
#include "User.h"

namespace ty {

class UserFactory {
public:
    /**
     * コンストラクタ
     */
    UserFactory(xn::Context& ctx);

    /**
     * デストラクタ
     */
    ~UserFactory(void);

    /**
     * User を取得する
     *
     * @return ユーザID が userId の User
     */
    User* get(int userId);

    /**
     * User 最大数
     */
    static const int MAX = 15;

private:
    /**
     * UserContext インスタンス
     */
    UserContext* context;

    /**
     * User リスト
     *
     * @see UserFactory::MAX
     */
    User* list[UserFactory::MAX];
};

} // namespace ty

#endif // _TYTHON_USER_FACTORY_H
