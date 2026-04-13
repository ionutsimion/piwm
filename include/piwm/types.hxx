#ifndef PIWM_TYPES_HXX
#define PIWM_TYPES_HXX

#include <struct.hxx>
#include <typedecl.hxx>

namespace piwm
{
    using Title = td::typedecl<std::string, TAG(Title)>;

    using Scalar = double;

    using X = td::typedecl<Scalar, TAG(XCoordinate)>;
    using Y = td::typedecl<Scalar, TAG(YCoordinate)>;
    using Position = tl::struct_t<X, Y>;

    using Width = td::typedecl<Scalar, TAG(Width)>;
    using Height = td::typedecl<Scalar, TAG(Height)>;
    using Size = tl::struct_t<Width, Height>;
}

#endif
