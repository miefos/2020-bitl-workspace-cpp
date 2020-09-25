#include <vector>

using namespace std;
namespace ds_course {
    struct Node {
    private:
        int val;
        vector<Node> children;
    public:
        Node(int vv);
        void addChild(const Node& nn);
        void reflect();
        void printPreorder();
        int getVal() const;
        vector<int> getChildren();
    };
}