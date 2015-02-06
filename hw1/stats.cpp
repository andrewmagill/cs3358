using namespace std;


class Stats {

   static const int MAX_SIZE = 10000;
   private:
      int numVars;
      double vars[MAX_SIZE];

   public:
      Stats();

      void clearData() {
         numVars = 0;
      }

      bool addVar(double var);

      void showData();
      double getAverage();
      double findHighest();
      double findLowest();
      double calcStdDeviation();

      int getNumVars() {
         return numVars;
      }

      static int getMaxSize() {
         return MAX_SIZE;
      }

};

