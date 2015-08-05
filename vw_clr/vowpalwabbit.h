/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD (revised)
license as described in the file LICENSE.
*/

#pragma once

#include "vw_clr.h"
#include "vw_base.h"
#include "vw_model.h"
#include "vw_prediction.h"
#include "vw_interface.h"

namespace VW
{
	ref class VowpalWabbitExampleBuilder;

	/// <summary>
	/// Simple string example based wrapper for vowpal wabbit.  
	/// </summary>
	/// <remarks>If possible use VowpalWabbit{T} types as this wrapper suffers from marshalling performance wise.</remarks> 
	public ref class VowpalWabbit : VowpalWabbitBase 
	{
	private:
		/// <summary>
		/// Select the right hash method based on args.
		/// </summary>
		Func<String^, unsigned long, size_t>^ GetHasher();

		/// <summary>
		/// The selected hasher method.
		/// </summary>
		/// <remarks>
		/// Avoiding if-else for hash function selection. Delegates outperform function pointers according to http://stackoverflow.com/questions/13443250/performance-of-c-cli-function-pointers-versus-net-delegates
		/// </remarks>
		initonly Func<String^, unsigned long, size_t>^ m_hasher;

	public:
		/// <summary>
		/// Initializes a new <see cref="VowpalWabbitBase"/> instance. 
		/// </summary>
		/// <param name="args">Command line arguments.</param>
		VowpalWabbit(VowpalWabbitSettings^ args);

		VowpalWabbit(String^ args);

		/// <summary>
		/// Run multi-passe training. 
		/// </summary>
		void RunMultiPass();

		/// <summary>
		/// Persist model to file specified by -i.
		/// </summary>
		void SaveModel();

		/// <summary>
		/// Persist model to <paramref name="filename"/>.
		/// </summary>
		/// <param name="filename">The destination filename for the model.</param>
		void SaveModel(String^ filename);

		/// <summary>
		/// Gets Collected performance statistics.
		/// </summary>
		property VowpalWabbitPerformanceStatistics^ PerformanceStatistics
		{
			VowpalWabbitPerformanceStatistics^ get();
		}

		VowpalWabbitExample^ ParseLine(String^ line);

		/// <summary>
		/// Hashes the given namespace <paramref name="s"/>.
		/// </summary>
		/// <param name="s">String to be hashed.</param>
		/// <returns>The resulting hash code.</returns>
		/// <remarks>The hash code depends on the vowpal wabbit instance as different has functions can be configured.</remarks>
		uint32_t HashSpaceNative(String^ s);

		/// <summary>
		/// Hashes the given namespace <paramref name="s"/>.
		/// </summary>
		/// <param name="s">String to be hashed.</param>
		/// <returns>The resulting hash code.</returns>
		/// <remarks>The hash code depends on the vowpal wabbit instance as different has functions can be configured.</remarks>
		uint32_t HashSpace(String^ s);

		/// <summary>
		/// Hash the given feature <paramref name="s"/>.
		/// </summary>
		/// <param name="s">String to be hashed.</param>
		/// <param name="u">Hash offset.</param>
		/// <returns>The resulting hash code.</returns>
		/// <remarks>The hash code depends on the vowpal wabbit instance as different has functions can be configured.</remarks>
		uint32_t HashFeatureNative(String^ s, unsigned long u);

		/// <summary>
		/// Hash the given feature <paramref name="s"/>.
		/// </summary>
		/// <param name="s">String to be hashed.</param>
		/// <param name="u">Hash offset.</param>
		/// <returns>The resulting hash code.</returns>
		/// <remarks>The hash code depends on the vowpal wabbit instance as different has functions can be configured.</remarks>
		uint32_t HashFeature(String^s, unsigned long u);

		/// <summary>
		/// The associated <see cref="VowpalWabbitBase"/> instance learns from this example and returns the prediction result for this example.
		/// </summary>
		/// <returns>The prediction result.</returns>
		/// <typeparam name="TPrediction">The prediction result type.</typeparam>
		generic<typename T>
		T Learn(VowpalWabbitExample^ ex, IVowpalWabbitPredictionFactory<T>^ predictionFactory);

		void Learn(VowpalWabbitExample^ ex);

		/// <summary>
		/// The associated <see cref="VowpalWabbitBase"/> instance predicts an outcome using this example.
		/// </summary>
		/// <returns>The prediction result.</returns>
		/// <typeparam name="TPrediction">The prediction result type.</typeparam>
		void Predict(VowpalWabbitExample^ ex);

		generic<typename T>
		T Predict(VowpalWabbitExample^ ex, IVowpalWabbitPredictionFactory<T>^ predictionFactory);

		void Learn(String^ line);

		void Predict(String^ line);

		generic<typename T>
		T Learn(String^ line, IVowpalWabbitPredictionFactory<T>^ predictionFactory);

		generic<typename T>
		T Predict(String^ line, IVowpalWabbitPredictionFactory<T>^ predictionFactory);

		void EndOfPass();

		/// <summary>
		/// Invokes the driver.
		/// </summary>
		void Driver();
	};
}