#ifndef DELETE_H
#define DELETE_H

namespace CP5 {
    class Delete {
    public:
        template<typename T> 
        auto operator()(T *p) const {
            delete p;
        }
    };
}

#endif // DELETE_H
