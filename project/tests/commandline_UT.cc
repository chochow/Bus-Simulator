/**
 * @file passengers_UT.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

/* STUDENTS: YOU MUST ADD YOUR PASSENGER UNIT TESTS TO THIS FILE. FORMAT YOUR
 * TESTS TO FIT THE SPECIFICATIONS GIVEN BY THE TESTS PROVIDED IN THIS FILE.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include "../src/configuration_simulator.h"
#include "../src/config_manager.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class commandline : public ::testing::Test {
 protected:

    ConfigurationSimulator* config_sim;
    
    virtual void SetUp() {
      ConfigManager* cm = new ConfigManager();
      config_sim = new ConfigurationSimulator(cm);
    }

    virtual void TearDown() {
      delete config_sim;
    }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/


TEST_F(commandline, CommandLineTests) {
   testing::internal::CaptureStderr();
    char* argv[]= {
      (char*) "./build/bin/configuration_sim",
        (char*) "config.txt",
           (char*) "xx",
        NULL
    };
    std::string result1 = config_sim->Checktime(argv);
    std::string output = testing::internal::GetCapturedStderr();
    std::string expectoutput = "length_of_simulation must be an intger great than 0\n";
    EXPECT_EQ(output, expectoutput);
    EXPECT_EQ(result1, "50");
}

TEST_F(commandline, CommandLine3Tests) {
    testing::internal::CaptureStderr();
    char* argv[]= {
      (char*) "./build/bin/configuration_sim",
        (char*) "config1.txt",
          (char*) "50",
          NULL
    };
    std::string result1 = config_sim->Checkfilename(argv);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "");
    EXPECT_EQ(result1, "config1.txt");
}
