#include "Circuit.h"

Circuit::Circuit(float variable, float feedbackGain)
	: feedbackGain(feedbackGain), variable(variable), delay(0)
{
	
}

void Circuit::removeElement(uint32_t index)
{
	elements.at(index);
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

const float& Circuit::getFeedbackGain() const
{
	return feedbackGain;
}

const float& Circuit::getVariable() const
{
	return variable;
}


float Circuit::performCircuit(float input, uint32_t iterator)
{
	input = variable * input + feedbackGain * delay.getBack();
	for(uint32_t i = 0; i < iterator; i++)
		for (auto& element : elements)
			input = element->execute(input);
	delay.execute(input);
	return input;
}

float Circuit::operator[](uint32_t index)
{
	return delay[index];
}


template<typename SomeElement>
inline const SomeElement& Circuit::getElement(uint32_t index) const
{
	return *static_cast<SomeElement*>(elements.at(index).get());
}
