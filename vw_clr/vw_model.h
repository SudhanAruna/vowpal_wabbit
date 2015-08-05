/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD (revised)
license as described in the file LICENSE.
*/

#pragma once

#include "vw_clr.h"
#include "vw_base.h"

namespace VW
{
	/// <summary>
	/// VowpalWabbit model wrapper.
	/// </summary>
	public ref class VowpalWabbitModel : public VowpalWabbitBase
	{
	private:
		/// <summary>
		/// Reference count.
		/// </summary>
		System::Int32 m_instanceCount;

	internal:
		/// <summary>
		/// Thread-safe increment of reference count.
		/// </summary>
		void IncrementReference();

		/// <summary>
		/// Thread-safe decrement of reference count.
		/// </summary>
		void DecrementReference();

		/// <summary>
		/// Cleanup.
		/// </summary>
		!VowpalWabbitModel();

	public:
		/// <summary>
		/// Initializes a new <see cref="VowpalWabbitModel"/> instance. 
		/// </summary>
		/// <param name="args">Command line arguments.</param>
		VowpalWabbitModel(VowpalWabbitSettings^ args);

		VowpalWabbitModel(String^ args);

		/// <summary>
		/// Cleanup.
		/// </summary>
		virtual ~VowpalWabbitModel();
	};
}