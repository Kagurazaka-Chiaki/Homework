#ifndef TEMP_SORT_HPP
#define TEMP_SORT_HPP

#include "templib/base.hpp"

namespace temp {

    template<class t_list>
    struct t_qsort {};

    template<>
    struct t_qsort<t_list<>> {
            using value = t_list<>;
    };

    template<int x, int... y>
    struct t_qsort<t_list<x, y...>> {

            template<int rhs>
            using lep = typename t_less<x>::template t_less_partial<rhs>;

            template<int rhs>
            using gtp = typename t_greater<x>::template t_greater_partial<rhs>;

            using value = typename t_concat<
                    typename t_qsort<typename t_filter<lep, t_list<y...>>::value>::value,
                    t_list<x>,
                    typename t_qsort<typename t_filter<gtp, t_list<y...>>::value>::value>::value;
    };


} // namespace temp

#endif // TEMP_SORT_HPP
