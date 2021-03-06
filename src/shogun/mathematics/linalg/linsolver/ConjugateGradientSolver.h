/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soumyajit De, Sunil Mahendrakar, Heiko Strathmann, Björn Esser
 */

#ifndef CONJUGATE_GRADIENT_SOLVER_H_
#define CONJUGATE_GRADIENT_SOLVER_H_

#include <shogun/lib/config.h>

#include <shogun/mathematics/linalg/linsolver/IterativeLinearSolver.h>

namespace shogun
{
template<class T> class CLinearOperator;
template<class T> class SGVector;

/**
 * @brief class that uses conjugate gradient method of solving a linear system
 * involving a real valued linear operator and vector. Useful for large sparse
 * systems involving sparse symmetric and positive-definite matrices.
 */
class CConjugateGradientSolver : public CIterativeLinearSolver<float64_t, float64_t>
{

public:
	/** default constructor */
	CConjugateGradientSolver();

	/** one arg constructor */
	CConjugateGradientSolver(bool store_residuals);

	/** destructor */
	virtual ~CConjugateGradientSolver();

	/**
	 * solve method for solving real linear systems
	 *
	 * @param A the linear operator of the system
	 * @param b the vector of the system
	 * @return the solution vector
	 */
	virtual SGVector<float64_t> solve(CLinearOperator<float64_t>* A,
		SGVector<float64_t> b);

	/** @return object name */
	virtual const char* get_name() const
	{
		return "ConjugateGradientSolver";
	}

};

}

#endif // CONJUGATE_GRADIENT_SOLVER_H_
