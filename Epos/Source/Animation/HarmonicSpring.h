#pragma once
//******************************************************************************
//https://news.ycombinator.com/item?id=8670432
//http://www.ryanjuckett.com/programming/damped-springs/
// CalcDampedSimpleHarmonicMotion
// This function will update the supplied position and velocity values over
// the given time according to the spring parameters.
// - An angular frequency is given to control how fast the spring oscillates.
// - A damping ratio is given to control how fast the motion decays.
//     damping ratio > 1: over damped
//     damping ratio = 1: critically damped
//     damping ratio < 1: under damped
//******************************************************************************
void CalcDampedSimpleHarmonicMotion
(
	float *pPos,            // position value to update
	float *pVel,            // velocity value to update
	float equilibriumPos,   // position to approach
	float deltaTime,        // time to update over
	float angularFrequency, // angular frequency of motion
	float dampingRatio      // damping ratio of motion
)
{
	const float epsilon = 0.0001f;

	// if there is no angular frequency, the spring will not move
	if (angularFrequency < epsilon)
		return;

	// clamp the damping ratio in legal range
	if (dampingRatio < 0.0f)
		dampingRatio = 0.0f;

	// calculate initial state in equilibrium relative space
	const float initialPos = *pPos - equilibriumPos;
	const float initialVel = *pVel;

	// if over-damped
	if (dampingRatio > 1.0f + epsilon)
	{
		// calculate constants based on motion parameters
		// Note: These could be cached off between multiple calls using the same
		//       parameters for deltaTime, angularFrequency and dampingRatio.
		const float za = -angularFrequency * dampingRatio;
		const float zb = angularFrequency * sqrtf(dampingRatio*dampingRatio - 1.0f);
		const float z1 = za - zb;
		const float z2 = za + zb;
		const float expTerm1 = expf(z1 * deltaTime);
		const float expTerm2 = expf(z2 * deltaTime);

		// update motion
		float c1 = (initialVel - initialPos*z2) / (-2.0f*zb); // z1 - z2 = -2*zb
		float c2 = initialPos - c1;
		*pPos = equilibriumPos + c1*expTerm1 + c2*expTerm2;
		*pVel = c1*z1*expTerm1 + c2*z2*expTerm2;
	}
	// else if critically damped
	else if (dampingRatio > 1.0f - epsilon)
	{
		// calculate constants based on motion parameters
		// Note: These could be cached off between multiple calls using the same
		//       parameters for deltaTime, angularFrequency and dampingRatio.
		const float expTerm = expf(-angularFrequency * deltaTime);

		// update motion
		float c1 = initialVel + angularFrequency * initialPos;
		float c2 = initialPos;
		float c3 = (c1*deltaTime + c2) * expTerm;
		*pPos = equilibriumPos + c3;
		*pVel = (c1*expTerm) - (c3*angularFrequency);
	}
	// else under-damped
	else
	{
		// calculate constants based on motion parameters
		// Note: These could be cached off between multiple calls using the same
		//       parameters for deltaTime, angularFrequency and dampingRatio.
		const float omegaZeta = angularFrequency * dampingRatio;
		const float alpha = angularFrequency * sqrt(1.0f - dampingRatio*dampingRatio);
		const float expTerm = expf(-omegaZeta * deltaTime);
		const float cosTerm = cosf(alpha * deltaTime);
		const float sinTerm = sinf(alpha * deltaTime);

		// update motion
		float c1 = initialPos;
		float c2 = (initialVel + omegaZeta*initialPos) / alpha;
		*pPos = equilibriumPos + expTerm*(c1*cosTerm + c2*sinTerm);
		*pVel = -expTerm*((c1*omegaZeta - c2*alpha)*cosTerm +
			(c1*alpha + c2*omegaZeta)*sinTerm);
	}
}