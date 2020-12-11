#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Node.h"


using namespace ds_course;
TEST_CASE("Test1", "[test1]")
{
    const char mode[] = "LEX";

    // create tree with "aaa", "bbb", "ccc"
    Node* root;
    root = Node::newNode("aaa");
    root = root->insert("bbb", mode);
    root = root->insert("ccc", mode);

    // min, max
    REQUIRE(root->minValueNode()->key == "aaa");
    REQUIRE(root->maxValueNode()->key == "ccc");

    // location
    REQUIRE(root->locateNodeByKey("aaa", mode) == "*L");
    REQUIRE(root->locateNodeByKey("bbb", mode) == "*");
    REQUIRE(root->locateNodeByKey("ccc", mode) == "*R");

    // badness
    REQUIRE(root->getBadness("ccc", mode) == 1);
    root = root->insert("ccc", mode);
    root = root->insert("ccc", mode);
    REQUIRE(root->getBadness("ccc", mode) == 3);

    // insert one more
    root = root->insert("ddd", mode);

    // min, max
    REQUIRE(root->minValueNode()->key == "aaa");
    REQUIRE(root->maxValueNode()->key == "ddd");

    // dump AVL
    REQUIRE(root->dumpAVL("_", "_", mode) == " (aaa,1) (bbb,1) (ccc,3) (ddd,1)");
    REQUIRE(root->dumpAVL("a", "_", mode) == " (aaa,1) (bbb,1) (ccc,3) (ddd,1)");
    REQUIRE(root->dumpAVL("a", "d", mode) == " (aaa,1) (bbb,1) (ccc,3)");
}