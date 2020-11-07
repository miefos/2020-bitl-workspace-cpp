#ifndef INC_2020_BITL_WORKSPACE_CPP_ALIEN_H
#define INC_2020_BITL_WORKSPACE_CPP_ALIEN_H

namespace ds_course {
    class Alien {
    private:
        int num;
        Alien* right;
        Alien* left;
        Alien* parent;
    public:
        explicit Alien(int nn);
        ~Alien();
        int getNum();
        Alien* getRight();
        Alien* getLeft();
        Alien* getParent();
        void setParent(Alien* al);
        void setRight(int key);
        void setLeft(int key);

    };
}


#endif //INC_2020_BITL_WORKSPACE_CPP_ALIEN_H
