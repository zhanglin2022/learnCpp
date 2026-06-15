#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

namespace CP5 {
    class DebugDelete {
    public:
        template <typename T> 
        auto operator()(T *p) const {
            delete p;
        }
    };
}

#endif // DEBUGDELETE_H
