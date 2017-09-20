#pragma once
namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales &s, const double ar[], int n);
	void setSales(Sales & s);
	void showSales(const Sales & s);


	//Chapter10_Assignment4 class definition
	class SALES
		{
		private:
			static const int quarters = 4;
			double m_sales[quarters];
			double m_min;
			double m_max;
			double m_average;

		public:
			SALES(double sales[quarters]=(0,0,0,0), double min = 0, double max = 0, double average = 0);
			~SALES();
			void SetSales();
			void ShowSales();
		};
}

