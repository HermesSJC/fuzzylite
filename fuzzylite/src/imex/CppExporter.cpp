/*
 Copyright © 2010-2015 by FuzzyLite Limited.
 All rights reserved.

 This file is part of fuzzylite®.

 fuzzylite® is free software: you can redistribute it and/or modify it under
 the terms of the FuzzyLite License included with the software.

 You should have received a copy of the FuzzyLite License along with 
 fuzzylite®. If not, see <http://www.fuzzylite.com/license/>.

 fuzzylite® is a registered trademark of FuzzyLite Limited.

 */

#include "fl/imex/CppExporter.h"

#include "fl/Headers.h"

#include <algorithm>

namespace fl {

    CppExporter::CppExporter(bool prefixNamespace, bool exportVariableName) : Exporter(),
    _prefixNamespace(prefixNamespace), _exportVariableName(exportVariableName) {
    }

    CppExporter::~CppExporter() {
    }

    std::string CppExporter::name() const {
        return "CppExporter";
    }

    std::string CppExporter::fl(const std::string& clazz) const {
        return _prefixNamespace ? "fl::" + clazz : clazz;
    }

    void CppExporter::setNamespacePrefixed(bool prefixNamespace) {
        this->_prefixNamespace = prefixNamespace;
    }

    bool CppExporter::isNamespacePrefixed() const {
        return this->_prefixNamespace;
    }

    void CppExporter::setVariableNameExported(bool exportVariableName) {
        this->_exportVariableName = exportVariableName;
    }

    bool CppExporter::isVariableNameExported() const {
        return this->_exportVariableName;
    }

    std::string CppExporter::toString(const Engine* engine) const {
        std::ostringstream cpp;
        if (not _prefixNamespace) cpp << "using namespace fl;\n\n";
        cpp << fl("Engine* ") << "engine = new " << fl("Engine;\n");
        cpp << "engine->setName(\"" << engine->getName() << "\");\n";

        cpp << "\n";

        for (std::size_t i = 0; i < engine->numberOfInputVariables(); ++i) {
            cpp << toString(engine->getInputVariable(i), engine) << "\n";
        }

        for (std::size_t i = 0; i < engine->numberOfOutputVariables(); ++i) {
            cpp << toString(engine->getOutputVariable(i), engine) << "\n";
        }

        for (std::size_t i = 0; i < engine->numberOfRuleBlocks(); ++i) {
            cpp << toString(engine->getRuleBlock(i), engine) << "\n";
        }

        return cpp.str();
    }

    std::string CppExporter::toString(const InputVariable* inputVariable, const Engine* engine) const {
        std::string name;
        if (isVariableNameExported()) {
            name = fl::Op::validName(inputVariable->getName());
        } else {
            name = "inputVariable";
            if (engine->numberOfInputVariables() > 1) {
                std::size_t index = std::distance(engine->inputVariables().begin(),
                        std::find(engine->inputVariables().begin(),
                        engine->inputVariables().end(), inputVariable));
                name += Op::str(index + 1);
            }
        }
        std::ostringstream ss;
        ss << fl("InputVariable* ") << name << " = new " << fl("InputVariable;\n");
        ss << name << "->setEnabled(" << (inputVariable->isEnabled() ? "true" : "false") << ");\n";
        ss << name << "->setName(\"" << inputVariable->getName() << "\");\n";
        ss << name << "->setRange(" <<
                toString(inputVariable->getMinimum()) << ", " <<
                toString(inputVariable->getMaximum()) << ");\n";
        ss << name << "->setLockValueInRange(" << (inputVariable->isLockValueInRange() ? "true" : "false") << ");\n";
        for (std::size_t t = 0; t < inputVariable->numberOfTerms(); ++t) {
            ss << name << "->addTerm(" << toString(inputVariable->getTerm(t)) << ");\n";
        }
        ss << "engine->addInputVariable(" << name << ");\n";
        return ss.str();
    }

    std::string CppExporter::toString(const OutputVariable* outputVariable, const Engine* engine) const {
        std::string name;
        if (isVariableNameExported()) {
            name = fl::Op::validName(outputVariable->getName());
        } else {
            name = "outputVariable";
            if (engine->numberOfOutputVariables() > 1) {
                std::size_t index = std::distance(engine->outputVariables().begin(),
                        std::find(engine->outputVariables().begin(),
                        engine->outputVariables().end(), outputVariable));
                name += Op::str(index + 1);
            }
        }
        std::ostringstream ss;
        ss << fl("OutputVariable* ") << name << " = new " << fl("OutputVariable;\n");
        ss << name << "->setEnabled(" << (outputVariable->isEnabled() ? "true" : "false") << ");\n";
        ss << name << "->setName(\"" << outputVariable->getName() << "\");\n";
        ss << name << "->setRange(" <<
                toString(outputVariable->getMinimum()) << ", " <<
                toString(outputVariable->getMaximum()) << ");\n";
        ss << name << "->setLockValueInRange(" <<
                (outputVariable->isLockValueInRange() ? "true" : "false") << ");\n";
        ss << name << "->fuzzyOutput()->setAggregation(" <<
                toString(outputVariable->fuzzyOutput()->getAggregation()) << ");\n";
        ss << name << "->setDefuzzifier(" <<
                toString(outputVariable->getDefuzzifier()) << ");\n";
        ss << name << "->setDefaultValue(" <<
                toString(outputVariable->getDefaultValue()) << ");\n";
        ss << name << "->setLockPreviousValue(" <<
                (outputVariable->isLockPreviousValue() ? "true" : "false") << ");\n";
        for (std::size_t t = 0; t < outputVariable->numberOfTerms(); ++t) {
            ss << name << "->addTerm(" << toString(outputVariable->getTerm(t)) << ");\n";
        }
        ss << "engine->addOutputVariable(" << name << ");\n";
        return ss.str();
    }

    std::string CppExporter::toString(const RuleBlock* ruleBlock, const Engine* engine) const {
        std::string name = "ruleBlock";
        if (engine->numberOfRuleBlocks() > 1) {
            std::size_t index = std::distance(engine->ruleBlocks().begin(),
                    std::find(engine->ruleBlocks().begin(),
                    engine->ruleBlocks().end(), ruleBlock));
            name += Op::str(index + 1);
        }
        std::ostringstream ss;
        ss << fl("RuleBlock* ") << name << " = new " << fl("RuleBlock;\n");
        ss << name << "->setEnabled(" << (ruleBlock->isEnabled() ? "true" : "false") << ");\n";
        ss << name << "->setName(\"" << ruleBlock->getName() << "\");\n";
        ss << name << "->setConjunction(" <<
                toString(ruleBlock->getConjunction()) << ");\n";
        ss << name << "->setDisjunction("
                << toString(ruleBlock->getDisjunction()) << ");\n";
        ss << name << "->setImplication("
                << toString(ruleBlock->getImplication()) << ");\n";
        ss << name << "->setActivation("
                << toString(ruleBlock->getActivation()) << ");\n";
        for (std::size_t r = 0; r < ruleBlock->numberOfRules(); ++r) {
            ss << name << "->addRule(" << "fl::Rule::parse(\"" <<
                    ruleBlock->getRule(r)->getText() << "\", engine));\n";
        }
        ss << "engine->addRuleBlock(" << name << ");\n";
        return ss.str();
    }

    std::string CppExporter::toString(scalar value) const {
        if (fl::Op::isNaN(value))
            return "fl::nan";
        if (fl::Op::isInf(value)) {
            return (value > 0 ? "fl::inf" : "-fl::inf");
        }
        return fl::Op::str(value);
    }

    std::string CppExporter::toString(const Term* term) const {
        if (not term) return "fl::null";

        if (const Discrete * discrete = dynamic_cast<const Discrete*> (term)) {
            std::ostringstream ss;
            ss << fl(term->className()) << "::create(\"" << term->getName() << "\", "
                    << discrete->xy().size() * 2 << ", "
                    << fl::Op::join(Discrete::toVector(discrete->xy()), ", ") << ")";
            return ss.str();
        }

        if (const Function * function = dynamic_cast<const Function*> (term)) {
            std::ostringstream ss;
            ss << fl(term->className()) << "::create(\"" << term->getName() << "\", "
                    << "\"" << function->getFormula() << "\", engine)";
            return ss.str();
        }

        if (const Linear * linear = dynamic_cast<const Linear*> (term)) {
            std::ostringstream ss;
            ss << fl(term->className()) << "::create(\"" << term->getName() << "\", "
                    << "engine, " << fl::Op::join(linear->coefficients(), ", ") << ")";
            return ss.str();
        }

        std::ostringstream ss;
        ss << "new " << fl(term->className()) << "(\"" << term->getName() << "\", "
                << Op::findReplace(term->parameters(), " ", ", ") << ")";
        return ss.str();
    }

    std::string CppExporter::toString(const Hedge * hedge) const {
        if (hedge->name() == Any().name()) return "new " + fl("Any");
        if (hedge->name() == Extremely().name()) return "new " + fl("Extremely");
        if (hedge->name() == Not().name()) return "new " + fl("Not");
        if (hedge->name() == Seldom().name()) return "new " + fl("Seldom");
        if (hedge->name() == Somewhat().name()) return "new " + fl("Somewhat");
        if (hedge->name() == Very().name()) return "new " + fl("Very");
        return "new " + fl(hedge->name());
    }

    std::string CppExporter::toString(const Norm* op) const {
        if (not op) return "fl::null";
        return "new " + fl(op->className());
    }

    std::string CppExporter::toString(const Defuzzifier* defuzzifier) const {
        if (not defuzzifier) return "fl::null";
        if (const IntegralDefuzzifier * integralDefuzzifier =
                dynamic_cast<const IntegralDefuzzifier*> (defuzzifier)) {
            return "new " + fl(integralDefuzzifier->className()) + "("
                    + Op::str(integralDefuzzifier->getResolution()) + ")";
        }
        if (const WeightedDefuzzifier * weightedDefuzzifier =
                dynamic_cast<const WeightedDefuzzifier*> (defuzzifier)) {
            return "new " + weightedDefuzzifier->className() +
                    "(\"" + weightedDefuzzifier->getTypeName() + "\")";
        }
        return "new " + fl(defuzzifier->className());
    }

    std::string CppExporter::toString(const Activation* activation) const {
        if (not activation) return "fl::null";
        return "new " + fl(activation->className());
    }

    CppExporter* CppExporter::clone() const {
        return new CppExporter(*this);
    }

}
