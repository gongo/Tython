// -*- C++ -*-

#ifndef _TYTHON_USER_FACTORY_H
#define _TYTHON_USER_FACTORY_H

#include "UserContext.h"
#include "User.h"

namespace ty {

class UserFactory {
public: 
    /**
     * xn::Context をセットする
     *
     * UserContext を生成し、User List を構築する
     */
    static void setContext(xn::Context *ctx);

    /**
     * User プールを破棄する
     */
    static void deleteContext(void);
    
    /**
     * User を取得する
     *
     * @return ユーザID が userId の User
     */
    static User* get(int userId);

    /**
     * User 最大数
     */
    static const int MAX = 8;

private:
    /**
     * コンストラクタ
     */
    UserFactory(void) {}

    /**
     * コピーコンストラクタ
     */
    UserFactory(const UserFactory& obj) {}

    /**
     * デストラクタ
     */
    ~UserFactory(void);

    /**
     * UserContext インスタンス
     */
    static UserContext* context;

    /**
     * User リスト
     *
     * @see UserFactory::MAX
     */
    static User* list[UserFactory::MAX];
};

} // namespace ty

#endif // _TYTHON_USER_FACTORY_H
