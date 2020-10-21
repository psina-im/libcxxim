
/// \file account_test.cpp
/// Contains unit tests for the account class.

#include "../cxxim/account.hpp"
#include "../cxxim/json.hpp"
#include <boost/test/unit_test.hpp>


namespace im::test {


BOOST_AUTO_TEST_SUITE(account_test)


/// Tests construction
BOOST_AUTO_TEST_CASE(ctor) {
    account acc{L"xuser@xserver", L"pass"};
    BOOST_CHECK(acc.user_id() == L"xuser@xserver");
    BOOST_CHECK(acc.password() == L"pass");
}


/// Tests saving account to JSON
BOOST_AUTO_TEST_CASE(save_json) {
    account acc{L"xuser@xserver", L"xpassword"};
    json_t json = acc;

    BOOST_CHECK(json.at("user-id").get<std::wstring>() == L"xuser@xserver");
    BOOST_CHECK(json.at("password").get<std::wstring>() == L"xpassword");
    BOOST_CHECK_EQUAL(json.dump(), R"({"password":"xpassword","user-id":"xuser@xserver"})");
}


/// Tests loading account from JSON
BOOST_AUTO_TEST_CASE(load_json) {
    json_t json = R"({ "user-id": "xuser@xserver", "password": "xpassword" })"_json;
    auto acc = json.get<account>();

    BOOST_CHECK(acc.user_id() == L"xuser@xserver");
    BOOST_CHECK(acc.password() == L"xpassword");
}


BOOST_AUTO_TEST_SUITE_END()


}
