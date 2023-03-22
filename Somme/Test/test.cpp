
//#include "pch.h"
#include"gtest/gtest.h"

extern "C" {
#include"../SOMME/somme.h"
}
extern "C" {
#include"../SOMME/application.h"
}



TEST(TestCaseName, TestName) {
	EXPECT_EQ(7, somme(3,4));
	EXPECT_TRUE(7 == somme(3, 4));
}

TEST(Mon_test_faux, Un_tres_mauvais_test) {
	EXPECT_EQ(7, 3);
}

//
//
//TEST(TestdeFonctions, TEST_Strlen2) {
//	char chaine[1] = "a";
//	EXPECT_EQ(strlen2(chaine), 1);
//}
//
//
//TEST(TestdeFonctions, TEST_strcpy2) {
//	strcpy2(chaine, "b");
//	EXPECT_STREQ(chaine, "b");
//}
//
//
//
//TEST(TestdeFonctions, TEST_strcat2) {
//	strcat2(chaine, "c");
//	EXPECT_STREQ(chaine, "bc");
//
//}
//
//TEST(TestdeFonctions, TEST_strncat2) {
//	strncat2(chaine, "d", 1);
//	EXPECT_STREQ(chaine, "bcd");
//}
//
//
//TEST(TestdeFonctions, TEST_strcmp2) {
//	int resultat = strcmp2("A", "a");
//	EXPECT_LT(resultat, 0);
//}
//
//
//TEST(TestdeFonctions, TEST_atoi2) {
//	int valeur = atoi2("12345");
//	EXPECT_EQ(12355, valeur);
//}
