#ifndef INC_2020_BITL_WORKSPACE_CPP_OUTOFBOUNDSEXCEPTIION_H
#define INC_2020_BITL_WORKSPACE_CPP_OUTOFBOUNDSEXCEPTIION_H

#include <string>
#include <iostream>

using namespace std;

namespace ds_course {
    class OutOfBoundsException {
    private:
      string msg;

    public:
      OutOfBoundsException(const string& msgg) {
        msg = msgg;
      }

      ~OutOfBoundsException() {

      }

      string getMessage() const {
        return msg;
      }

    };
}


#endif //INC_2020_BITL_WORKSPACE_CPP_OUTOFBOUNDSEXCEPTIION_H
