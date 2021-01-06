#pragma once
#include "../Effects/Effects.h"
#include "../Elements/Elements.h"
#include "../Holders/Holders.h"

/// <summary>
/// Class for simulated circuit with possibility of adding other elements such as filters or delays
/// </summary>
class Circuit
{
	/// <summary>
	/// Vector of elements
	/// </summary>
	std::vector<std::unique_ptr<Element>> elements = std::vector<std::unique_ptr<Element>>();

	/// <summary>
	/// Past values of given circuit
	/// </summary>
	Delay delay;

	/// <summary>
	/// Gain from circuit feedback
	/// </summary>
	float feedbackGain;

	/// <summary>
	/// Certain vriable by which the input value is multiplied by
	/// </summary>
	float variable;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="variable">sets the variable</param>
	/// <param name="feedbackGain">setd the feedback gain</param>
	Circuit(float variable = 1.f, float feedbackGain = 0.2f);

	
	~Circuit() = default;

	/// <summary>
	/// Adds new unique ptr to the elements vector
	/// </summary>
	/// <typeparam name="SomeElement">Element to be inserted into vector</typeparam>
	/// <typeparam name="...Args">Construction arguments for given element</typeparam>
	/// <param name="...args">Construction varargs for given element</param>
	template <typename SomeElement, typename... Args>
	void addElement(Args&&... args)
	{
		SomeElement* new_element(new SomeElement(std::forward<Args>(args)...));
		std::unique_ptr<Element> new_unique_element{ new_element };
		elements.emplace_back(std::move(new_unique_element));
	}

	/// <summary>
	/// Remove element at given index
	/// </summary>
	/// <param name="index">Index at which the element resides</param>
	void removeElement(uint32_t index);

	/// <summary>
	/// Removes all the elements from the vector
	/// </summary>
	void removeAll();

	/// <summary>
	/// Resets element at index
	/// </summary>
	/// <param name="index">index of given element</param>
	void resetElement(uint32_t index);

	/// <summary>
	/// Resets the previous values present in the circuit
	/// </summary>
	void resetCircuit();

	/// <summary>
	/// Resets all elements and resets circuit
	/// </summary>
	void resetAll();

	/// <summary>
	/// Gets size of the delay
	/// </summary>
	/// <returns>Size of the delay in samples</returns>
	uint32_t getDelay() const;

	/// <summary>
	/// Sets the delay
	/// </summary>
	/// <param name="value">Size of the delay in samples</param>
	void setDelay(uint32_t value);

	/// <summary>
	/// Gets element of a given type
	/// </summary>
	/// <typeparam name="SomeElement">Element type</typeparam>
	/// <param name="index">Index at which the element resides</param>
	/// <returns>Pointer to given element</returns>
	template <typename SomeElement>
	const SomeElement& getElement(uint32_t index) const;

	/// <summary>
	/// Gets and sets feedbackGain
	/// </summary>
	/// <returns>feedbackGain reference</returns>
	const float& getFeedbackGain() const;

	/// <summary>
	/// Gets and sets variable
	/// </summary>
	/// <returns>variable reference</returns>
	const float& getVariable() const;

	/// <summary>
	/// Refactors input by every element in the circuit by given number of times
	/// </summary>
	/// <param name="input">Input sample</param>
	/// <param name="iterator">Number of times being refactored</param>
	/// <returns>output value</returns>
	float performCircuit(float input, uint32_t iterator = 1);

	/// <summary>
	/// Gets previous sample at position index
	/// </summary>
	/// <param name="index">Position of searched sample</param>
	/// <returns>Sample at given index</returns>
	float operator [](uint32_t index);


};
