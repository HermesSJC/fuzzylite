#include <fl/Headers.h>

int main(int argc, char** argv){
fl::Engine* engine = new fl::Engine;
engine->setName("invkine2");
engine->addHedge(new fl::Any);
engine->addHedge(new fl::Extremely);
engine->addHedge(new fl::Not);
engine->addHedge(new fl::Seldom);
engine->addHedge(new fl::Somewhat);
engine->addHedge(new fl::Very);

fl::InputVariable* inputVariable1 = new fl::InputVariable;
inputVariable1->setName("input1");
inputVariable1->setRange(-6.287, 17.000);

inputVariable1->addTerm(new fl::Bell("in1mf1", -5.763, 3.015, 1.851));
inputVariable1->addTerm(new fl::Bell("in1mf2", -1.624, 3.130, 2.111));
inputVariable1->addTerm(new fl::Bell("in1mf3", 3.552, 3.193, 2.104));
inputVariable1->addTerm(new fl::Bell("in1mf4", 8.273, 2.907, 1.985));
inputVariable1->addTerm(new fl::Bell("in1mf5", 13.232, 2.708, 2.056));
inputVariable1->addTerm(new fl::Bell("in1mf6", 17.783, 1.635, 1.897));
engine->addInputVariable(inputVariable1);

fl::InputVariable* inputVariable2 = new fl::InputVariable;
inputVariable2->setName("input2");
inputVariable2->setRange(0.000, 16.972);

inputVariable2->addTerm(new fl::Bell("in2mf1", 0.005, 1.877, 1.995));
inputVariable2->addTerm(new fl::Bell("in2mf2", 3.312, 2.017, 1.829));
inputVariable2->addTerm(new fl::Bell("in2mf3", 6.568, 2.261, 1.793));
inputVariable2->addTerm(new fl::Bell("in2mf4", 10.111, 2.741, 1.978));
inputVariable2->addTerm(new fl::Bell("in2mf5", 14.952, 2.045, 1.783));
inputVariable2->addTerm(new fl::Bell("in2mf6", 17.910, 0.824, 1.734));
engine->addInputVariable(inputVariable2);

fl::OutputVariable* outputVariable1 = new fl::OutputVariable;
outputVariable1->setName("output");
outputVariable1->setRange(0.000, 3.100);
outputVariable1->setLockOutputRange(false);
outputVariable1->setDefaultValue(fl::nan);
outputVariable1->setLockValidOutput(false);
outputVariable1->setDefuzzifier(new fl::WeightedAverage());
outputVariable1->output()->setAccumulation(new fl::Maximum);

outputVariable1->addTerm(fl::Linear::create("out1mf1", engine->inputVariables(), -0.048, 1.456, 2.222));
outputVariable1->addTerm(fl::Linear::create("out1mf2", engine->inputVariables(), -0.218, -0.305, 2.042));
outputVariable1->addTerm(fl::Linear::create("out1mf3", engine->inputVariables(), 0.026, -0.141, 3.067));
outputVariable1->addTerm(fl::Linear::create("out1mf4", engine->inputVariables(), 0.052, -0.150, 3.419));
outputVariable1->addTerm(fl::Linear::create("out1mf5", engine->inputVariables(), 0.113, -0.189, 4.339));
outputVariable1->addTerm(fl::Linear::create("out1mf6", engine->inputVariables(), 2.543, 0.361, -2.738));
outputVariable1->addTerm(fl::Linear::create("out1mf7", engine->inputVariables(), 2.517, -6.809, 23.353));
outputVariable1->addTerm(fl::Linear::create("out1mf8", engine->inputVariables(), -0.208, -0.394, 4.472));
outputVariable1->addTerm(fl::Linear::create("out1mf9", engine->inputVariables(), -0.046, -0.300, 4.452));
outputVariable1->addTerm(fl::Linear::create("out1mf10", engine->inputVariables(), -0.006, -0.217, 4.195));
outputVariable1->addTerm(fl::Linear::create("out1mf11", engine->inputVariables(), 0.089, -0.254, 4.992));
outputVariable1->addTerm(fl::Linear::create("out1mf12", engine->inputVariables(), -0.033, 0.103, -2.012));
outputVariable1->addTerm(fl::Linear::create("out1mf13", engine->inputVariables(), 1.355, 1.228, -5.678));
outputVariable1->addTerm(fl::Linear::create("out1mf14", engine->inputVariables(), -0.245, -0.124, 3.753));
outputVariable1->addTerm(fl::Linear::create("out1mf15", engine->inputVariables(), -0.099, -0.111, 3.304));
outputVariable1->addTerm(fl::Linear::create("out1mf16", engine->inputVariables(), -0.052, -0.163, 3.560));
outputVariable1->addTerm(fl::Linear::create("out1mf17", engine->inputVariables(), 0.099, -0.260, 4.662));
outputVariable1->addTerm(fl::Linear::create("out1mf18", engine->inputVariables(), 0.082, -1.849, 31.104));
outputVariable1->addTerm(fl::Linear::create("out1mf19", engine->inputVariables(), 2.180, -2.963, -0.061));
outputVariable1->addTerm(fl::Linear::create("out1mf20", engine->inputVariables(), -0.982, 0.510, 5.657));
outputVariable1->addTerm(fl::Linear::create("out1mf21", engine->inputVariables(), -0.087, -0.179, 3.744));
outputVariable1->addTerm(fl::Linear::create("out1mf22", engine->inputVariables(), -0.124, -0.161, 4.094));
outputVariable1->addTerm(fl::Linear::create("out1mf23", engine->inputVariables(), 0.383, 0.007, -1.559));
outputVariable1->addTerm(fl::Linear::create("out1mf24", engine->inputVariables(), -8.415, 2.083, 5.177));
outputVariable1->addTerm(fl::Linear::create("out1mf25", engine->inputVariables(), 1.721, -15.079, -0.687));
outputVariable1->addTerm(fl::Linear::create("out1mf26", engine->inputVariables(), -1.043, -0.786, 20.510));
outputVariable1->addTerm(fl::Linear::create("out1mf27", engine->inputVariables(), -0.249, -0.396, 6.995));
outputVariable1->addTerm(fl::Linear::create("out1mf28", engine->inputVariables(), -0.076, -0.245, 4.416));
outputVariable1->addTerm(fl::Linear::create("out1mf29", engine->inputVariables(), 0.765, -1.488, 17.384));
outputVariable1->addTerm(fl::Linear::create("out1mf30", engine->inputVariables(), -21.210, -43.022, -2.522));
outputVariable1->addTerm(fl::Linear::create("out1mf31", engine->inputVariables(), -0.661, 3.523, 6.215));
outputVariable1->addTerm(fl::Linear::create("out1mf32", engine->inputVariables(), -1.998, 1.582, 33.256));
outputVariable1->addTerm(fl::Linear::create("out1mf33", engine->inputVariables(), -2.068, 5.673, 6.520));
outputVariable1->addTerm(fl::Linear::create("out1mf34", engine->inputVariables(), -5.044, 7.093, 3.516));
outputVariable1->addTerm(fl::Linear::create("out1mf35", engine->inputVariables(), -46.049, -35.021, -2.926));
outputVariable1->addTerm(fl::Linear::create("out1mf36", engine->inputVariables(), -0.448, -0.770, -0.041));
engine->addOutputVariable(outputVariable1);

fl::RuleBlock* ruleblock1 = new fl::RuleBlock;
ruleblock1->setName("");
ruleblock1->setTnorm(new fl::AlgebraicProduct);
ruleblock1->setSnorm(new fl::Maximum);
ruleblock1->setActivation(new fl::AlgebraicProduct);

ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf1 then output is out1mf1", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf2 then output is out1mf2", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf3 then output is out1mf3", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf4 then output is out1mf4", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf5 then output is out1mf5", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf1 and input2 is in2mf6 then output is out1mf6", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf1 then output is out1mf7", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf2 then output is out1mf8", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf3 then output is out1mf9", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf4 then output is out1mf10", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf5 then output is out1mf11", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf2 and input2 is in2mf6 then output is out1mf12", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf1 then output is out1mf13", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf2 then output is out1mf14", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf3 then output is out1mf15", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf4 then output is out1mf16", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf5 then output is out1mf17", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf3 and input2 is in2mf6 then output is out1mf18", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf1 then output is out1mf19", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf2 then output is out1mf20", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf3 then output is out1mf21", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf4 then output is out1mf22", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf5 then output is out1mf23", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf4 and input2 is in2mf6 then output is out1mf24", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf1 then output is out1mf25", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf2 then output is out1mf26", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf3 then output is out1mf27", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf4 then output is out1mf28", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf5 then output is out1mf29", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf5 and input2 is in2mf6 then output is out1mf30", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf1 then output is out1mf31", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf2 then output is out1mf32", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf3 then output is out1mf33", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf4 then output is out1mf34", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf5 then output is out1mf35", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if input1 is in1mf6 and input2 is in2mf6 then output is out1mf36", engine));
engine->addRuleBlock(ruleblock1);


}
