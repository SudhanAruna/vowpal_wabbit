/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD (revised)
license as described in the file LICENSE.
*/

#pragma once

#include "vw_clr.h"

namespace VW
{
	ref class VowpalWabbitExample;
	ref class VowpalWabbit;
	
	generic<typename T>
	public interface class IVowpalWabbitPredictionFactory
	{
	public:
		T Create(vw* vw, example* ex);
	};

	/// <summary>
	/// A scalar prediction result.
	/// </summary>
	public ref class VowpalWabbitScalarPredictionFactory sealed : IVowpalWabbitPredictionFactory<float>
	{
	public:
		/// <summary>
		/// Extracts prediction results from example.
		/// </summary>
		virtual float Create(vw* vw, example* ex) sealed;
	};

	/// <summary>
	/// A cost sensitive prediction result.
	/// </summary>
	public ref class VowpalWabbitCostSensitivePredictionFactory sealed : IVowpalWabbitPredictionFactory<float>
	{
	public:
		/// <summary>
		/// Extracts prediction results from example. The cost sensitive prediction.
		/// </summary>
		virtual float Create(vw* vw, example* ex) sealed;
	};

	/// <summary>
	/// A multi label prediction result.
	/// </summary>
	public ref class VowpalWabbitMultilabelPredictionFactory sealed : IVowpalWabbitPredictionFactory<cli::array<int>^>
	{
	public:
		/// <summary>
		/// Extracts prediction results from example. The
		/// </summary>
		virtual cli::array<int>^ Create(vw* vw, example* ex) sealed;
	};

	/// <summary>
	/// A topic prediction result.
	/// </summary>
	public ref class VowpalWabbitTopicPredictionFactory sealed : IVowpalWabbitPredictionFactory<cli::array<float>^>
	{
	public:
		/// <summary>
		/// Extracts prediction results from example. The predicted topics.
		/// </summary>
		virtual cli::array<float>^ Create(vw* vw, example* ex) sealed;
	};

	public ref class VowpalWabbitPredictionType sealed abstract
	{
	public:
		static initonly VowpalWabbitScalarPredictionFactory^ Scalar = gcnew VowpalWabbitScalarPredictionFactory;
		static initonly VowpalWabbitCostSensitivePredictionFactory^ CostSensitive = gcnew VowpalWabbitCostSensitivePredictionFactory;
		static initonly VowpalWabbitMultilabelPredictionFactory^ Multilabel = gcnew VowpalWabbitMultilabelPredictionFactory;
		static initonly VowpalWabbitTopicPredictionFactory^ Topic = gcnew VowpalWabbitTopicPredictionFactory;
	};
}