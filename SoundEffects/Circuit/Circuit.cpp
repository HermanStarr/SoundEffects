#include "Circuit.h"

Circuit::Circuit(double variable, double feedbackGain)
	: feedbackGain(feedbackGain), variable(variable), delay(0)
{
	
}

template<typename SomeElement>
inline const SomeElement& Circuit::getElement(uint32_t index) const
{
	return *static_cast<SomeElement*>(elements.at(index).get());
}

void Circuit::removeElement(uint32_t index)
{
	elements.erase(elements.begin() + index);
}

void Circuit::removeAll()
{
	elements.clear();
	resetCircuit();
}

void Circuit::resetElement(uint32_t index)
{
	elements.at(index)->reset();
}

void Circuit::resetCircuit()
{
	delay.reset();
}

void Circuit::resetAll()
{
	resetCircuit();
	for (auto& element : elements)
		element.reset();
}

uint32_t Circuit::getDelay() const
{
	return delay.getDelay();
}

void Circuit::setDelay(uint32_t value)
{
	delay.setDelay(value);
}

const double Circuit::getFeedbackGain() const
{
	return feedbackGain;
}

void Circuit::setFeedbackGain(double feedbackGain)
{
	this->feedbackGain = feedbackGain;
}

const double Circuit::getVariable() const
{
	return variable;
}

const void Circuit::setVariable(double variable)
{
	this->variable = variable;
}

int32_t Circuit::performCircuit(int32_t input, uint32_t iterator)
{
	input = static_cast<int32_t>(variable * input + feedbackGain * delay.getBack());
	for (uint32_t i = 0; i < iterator; i++)
		for (auto& element : elements)
			input = element->execute(input);
	delay.execute(input);
	return input;
}


float Circuit::performCircuit(float input, uint32_t iterator)
{
	input = static_cast<float>(variable * input + feedbackGain * delay.getBack());
	for(uint32_t i = 0; i < iterator; i++)
		for (auto& element : elements)
			input = element->execute(input);
	delay.execute(input);
	return input;
}

double Circuit::performCircuit(double input, uint32_t iterator)
{
	input = variable * input + feedbackGain * delay.getBack();
	for (uint32_t i = 0; i < iterator; i++)
		for (auto& element : elements)
			input = element->execute(input);
	delay.execute(input);
	return input;
}

const double Circuit::operator[](uint32_t index) const
{
	return delay[index];
}

