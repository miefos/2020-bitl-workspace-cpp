#include <vector>

using namespace std;
namespace ds_course {
    struct Node {
    private:
        int val;
        vector<Node*> children;
    public:
        explicit Node(int vv);
        void addChild(Node* nn);
        void reflect();
        void printPreorder();
        int getVal() const;
        vector<int> getChildren();
    };
}