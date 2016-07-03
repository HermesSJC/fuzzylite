/*
 Copyright (C) 2010-2016 by FuzzyLite Limited.
 All rights reserved.

 This file is part of fuzzylite(R).

 fuzzylite is free software: you can redistribute it and/or modify it under
 the terms of the FuzzyLite License included with the software.

 You should have received a copy of the FuzzyLite License along with
 fuzzylite. If not, see <http://www.fuzzylite.com/license/>.

 fuzzylite(R) is a registered trademark of FuzzyLite Limited.
 */

#include "fl/norm/t/AlgebraicProduct.h"

namespace fl {

    std::string AlgebraicProduct::className() const {
        return "AlgebraicProduct";
    }

    Complexity AlgebraicProduct::complexity() const {
        return Complexity().arithmetic(1);
    }

    scalar AlgebraicProduct::compute(scalar a, scalar b) const {
        return a * b;
    }

    AlgebraicProduct* AlgebraicProduct::clone() const {
        return new AlgebraicProduct(*this);
    }

    TNorm* AlgebraicProduct::constructor() {
        return new AlgebraicProduct;
    }

}
