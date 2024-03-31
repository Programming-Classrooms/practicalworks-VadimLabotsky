#include "../matrix/Matrix.hpp"

int main()
{
	try
	{
		Matrix mtrx, mtrx1;

		std::cin >> mtrx;
		std::cin >> mtrx1;

		if (mtrx == mtrx1) {
		std::cout << "mtrx == mtrx1" << '\n';
		}
		else {
			std::cout << "mtrx != mtrx1" << '\n';
		}

		if (mtrx != mtrx1) {
			std::cout << "mtrx != mtrx1" << '\n';
		}
		else {
			std::cout << "mtrx == mtrx1" << '\n';
		}
		std::cout << '\n' << '\n';


		std::cout << "mtrx + mtrx1\n" << mtrx + mtrx1;
		std::cout << "mtrx\n" << mtrx;
		std::cout << "mtrx - mtrx1\n" << mtrx - mtrx1;
		std::cout << "mtrx\n" << mtrx;
		std::cout << "mtrx * mtrx1\n" << mtrx * mtrx1;
		std::cout << "mtrx1\n" << mtrx;
		std::cout << '\n' << '\n';


		mtrx += mtrx1;
		std::cout << "mtrx += mtrx1\n" << mtrx;
		mtrx -= mtrx1;
		std::cout << "mtrx -= mtrx1\n"<< mtrx;
		mtrx *= mtrx1;
		std::cout << "mtrx *= mtrx1\n" << mtrx;
		std::cout << '\n' << '\n';

	
		std::cout << "mtrx * 3\n" << mtrx * 3;
		std::cout << "mtrx\n" << mtrx;
		std::cout << "mtrx1 / 3\n" << mtrx1 / 3;
		std::cout << "mtrx1\n" << mtrx;
		std::cout << '\n' << '\n';


		mtrx *= 3;
		std::cout << "mtrx *= 3\n" << mtrx;
		mtrx /= 3;
		std::cout << "mtrx /= 3\n" << mtrx;
		std::cout << '\n' << '\n';


		std::cout << "3 * mtrx\n" <<  3 * mtrx;
		std::cout << "mtrx\n" << mtrx;
		std::cout << "3 / mtrx1\n" <<  3 / mtrx1;
		std::cout << "mtrx1\n" << mtrx;
		std::cout << '\n' << '\n';


		3 *= mtrx;
		std::cout << "mtrx *= 3\n" << mtrx;
		3 /= mtrx;
		std::cout << "mtrx /= 3\n" << mtrx;
		std::cout << '\n' << '\n';
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what();
	}
	
	return 0;
}
