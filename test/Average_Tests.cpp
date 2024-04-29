#include <gtest/gtest.h>
#include "../Average.hpp"
#include <iostream>
#include <fstream>
#include <string>



std::vector<double> Load_Line_To_Vector(const std::string& str) {
    std::istringstream iss(str);
    std::vector<double> tokens = {};
    if (str.empty()) {
        tokens.push_back(0);
        return tokens;
    }
    double num;
    while (iss >> num) {
        tokens.push_back(num);
    }
    return tokens;
}

void Test_File(const std::string& file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::string answer;
    std::vector<double> v;
    while (std::getline(file, line)){
        v = Load_Line_To_Vector(line);
        getline(file, answer);
        double expected = std::stod(answer);
        EXPECT_EQ(Average(v), expected);
        v.clear();
    }
}

TEST(AverageTests, Testing_Integer){

    Test_File("../../test/Test_Integer.txt");
}

TEST(AverageTests, Testing_Double){
    Test_File("../../test/Test_Double.txt");
}

TEST(AverageTests, Testing_Wrong){
    Test_File("../../test/Test_Wrong.txt");
}

TEST(AverageTests, Testing_Empty){
    Test_File("../../test/Test_Empty.txt");
}

TEST(AverageTests, Testing_One){
    EXPECT_EQ(Average({1}), 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

