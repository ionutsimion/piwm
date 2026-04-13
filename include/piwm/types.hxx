#ifndef PIWM_TYPES_HXX
#define PIWM_TYPES_HXX

#include <typelists/struct.hxx>

namespace piwm
{
    using Title = pi::td::typedecl<std::string, TAG(Title)>;

    using Scalar = double;

    using X = pi::td::typedecl<Scalar, TAG(XCoordinate)>;
    using Y = pi::td::typedecl<Scalar, TAG(YCoordinate)>;
    using Position = pi::tl::struct_t<X, Y>;

    using Width = pi::td::typedecl<Scalar, TAG(Width)>;
    using Height = pi::td::typedecl<Scalar, TAG(Height)>;
    using Size = pi::tl::struct_t<Width, Height>;
}

#endif
