#include <fl/Headers.h>

int main(int argc, char** argv){
fl::Engine* engine = new fl::Engine;
engine->setName("slcpp");
engine->addHedge(new fl::Any);
engine->addHedge(new fl::Extremely);
engine->addHedge(new fl::Not);
engine->addHedge(new fl::Seldom);
engine->addHedge(new fl::Somewhat);
engine->addHedge(new fl::Very);

fl::InputVariable* inputVariable1 = new fl::InputVariable;
inputVariable1->setName("in1");
inputVariable1->setRange(-0.300, 0.300);

engine->addInputVariable(inputVariable1);

fl::InputVariable* inputVariable2 = new fl::InputVariable;
inputVariable2->setName("in2");
inputVariable2->setRange(-1.000, 1.000);

engine->addInputVariable(inputVariable2);

fl::InputVariable* inputVariable3 = new fl::InputVariable;
inputVariable3->setName("in3");
inputVariable3->setRange(-3.000, 3.000);

engine->addInputVariable(inputVariable3);

fl::InputVariable* inputVariable4 = new fl::InputVariable;
inputVariable4->setName("in4");
inputVariable4->setRange(-3.000, 3.000);

engine->addInputVariable(inputVariable4);

fl::InputVariable* inputVariable5 = new fl::InputVariable;
inputVariable5->setName("in5");
inputVariable5->setRange(-3.000, 3.000);

engine->addInputVariable(inputVariable5);

fl::InputVariable* inputVariable6 = new fl::InputVariable;
inputVariable6->setName("in6");
inputVariable6->setRange(-3.000, 3.000);

engine->addInputVariable(inputVariable6);

fl::InputVariable* inputVariable7 = new fl::InputVariable;
inputVariable7->setName("polelength");
inputVariable7->setRange(0.500, 1.500);

inputVariable7->addTerm(new fl::ZShape("mf1", 0.500, 0.600));
inputVariable7->addTerm(new fl::PiShape("mf2", 0.500, 0.600, 0.600, 0.700));
inputVariable7->addTerm(new fl::PiShape("mf3", 0.600, 0.700, 0.700, 0.800));
inputVariable7->addTerm(new fl::PiShape("mf4", 0.700, 0.800, 0.800, 0.900));
inputVariable7->addTerm(new fl::PiShape("mf5", 0.800, 0.900, 0.900, 1.000));
inputVariable7->addTerm(new fl::PiShape("mf6", 0.900, 1.000, 1.000, 1.100));
inputVariable7->addTerm(new fl::PiShape("mf7", 1.000, 1.100, 1.100, 1.200));
inputVariable7->addTerm(new fl::PiShape("mf8", 1.100, 1.200, 1.200, 1.300));
inputVariable7->addTerm(new fl::PiShape("mf9", 1.200, 1.300, 1.300, 1.400));
inputVariable7->addTerm(new fl::PiShape("mf10", 1.300, 1.400, 1.400, 1.500));
inputVariable7->addTerm(new fl::SShape("mf11", 1.400, 1.500));
engine->addInputVariable(inputVariable7);

fl::OutputVariable* outputVariable1 = new fl::OutputVariable;
outputVariable1->setName("out");
outputVariable1->setRange(-10.000, 10.000);
outputVariable1->setLockOutputRange(false);
outputVariable1->setDefaultValue(fl::nan);
outputVariable1->setLockValidOutput(false);
outputVariable1->setDefuzzifier(new fl::WeightedAverage());
outputVariable1->output()->setAccumulation(new fl::Maximum);

outputVariable1->addTerm(fl::Linear::create("outmf1", engine->inputVariables(), 168.400, 31.000, -188.050, -49.250, -1.000, -2.700, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf2", engine->inputVariables(), 233.950, 47.190, -254.520, -66.580, -1.000, -2.740, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf3", engine->inputVariables(), 342.940, 74.730, -364.370, -95.230, -1.000, -2.780, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf4", engine->inputVariables(), 560.710, 130.670, -582.960, -152.240, -1.000, -2.810, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf5", engine->inputVariables(), 1213.880, 300.190, -1236.900, -322.800, -1.000, -2.840, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf6", engine->inputVariables(), 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf7", engine->inputVariables(), -1399.120, -382.950, 1374.630, 358.340, -1.000, -2.900, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf8", engine->inputVariables(), -746.070, -213.420, 720.900, 187.840, -1.000, -2.930, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf9", engine->inputVariables(), -528.520, -157.460, 502.680, 130.920, -1.000, -2.960, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf10", engine->inputVariables(), -419.870, -129.890, 393.380, 102.410, -1.000, -2.980, 0.000, 0.000));
outputVariable1->addTerm(fl::Linear::create("outmf11", engine->inputVariables(), -354.770, -113.680, 327.650, 85.270, -1.000, -3.010, 0.000, 0.000));
engine->addOutputVariable(outputVariable1);

fl::RuleBlock* ruleblock1 = new fl::RuleBlock;
ruleblock1->setName("");
ruleblock1->setTnorm(new fl::AlgebraicProduct);
ruleblock1->setSnorm(new fl::Maximum);
ruleblock1->setActivation(new fl::AlgebraicProduct);

ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf1 then out is outmf1", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf2 then out is outmf2", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf3 then out is outmf3", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf4 then out is outmf4", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf5 then out is outmf5", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf6 then out is outmf6", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf7 then out is outmf7", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf8 then out is outmf8", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf9 then out is outmf9", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf10 then out is outmf10", engine));
ruleblock1->addRule(fl::FuzzyRule::parse("if polelength is mf11 then out is outmf11", engine));
engine->addRuleBlock(ruleblock1);


}
