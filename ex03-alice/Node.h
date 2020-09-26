#include <vector>

using namespace std;
namespace ds_course {
    struct Node {
    private:
        int val;
        int parentVal = -1;
        vector<Node*> children;
    public:
        explicit Node(int vv);
        void addChild(Node* nn);
        void reflect();
        void printPreorder();
        void setParentVal(int);
        int getVal() const;
        int getParentVal() const;
        vector<int> getChildren();
    };
}