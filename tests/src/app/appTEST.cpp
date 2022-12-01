#include <gtest/gtest.h>
#include "app/app.hpp"

TEST (APP_TEST, GetXDefault )
{
    A a;

    EXPECT_EQ( a.GetX(), 1 );
}

TEST (APP_TEST, GetXAssigned )
{
    A a{10, 20};

    EXPECT_EQ( a.GetX(), 10 );
}

