// -*- C++ -*-

#ifndef _TYTHON_USER_FACTORY_H
#define _TYTHON_USER_FACTORY_H

#include "UserContext.h"
#include "User.h"

class UserFactory {
public: 
    /**
     * xn::Context をセットする
     *
     * UserContext を生成し、User List を構築する
     */
    static void setContext(xn::Context *ctx);
    
    /**
     * User を取得する
     *
     * @todo userId が 1 から UserFactory::MAX の範囲外の例外処理
     *
     * @return ユーザID が userId の User
     */
    static User* get(int userId);

    /**
     * User 最大数
     */
    static const int MAX;

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

    static UserContext* context;

    /**
     * User リスト
     *
     * @see UserFactory::MAX
     */
    static User** list;
};

#endif // _TYTHON_USER_FACTORY_H
