
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "luv_color_histogram.hh"

using namespace std;
using namespace jir;
using namespace boost;
using namespace boost::filesystem;

bool verify_folder(path& p){
	if (!exists(p)){
		cerr<< "Folder "<< p.c_str()<< " does not exist"<< endl;
		return false;
	}
	if (!(is_directory(p))){
		cerr<< p.c_str()<< " is not a folder."<< endl;
		return false;
	}
	return true;
}

void load(path& p, vector<LuvColorHistogram>& hist_vector){
	directory_iterator it(p);
	//directory_iterator end_it;
	for(auto& entry : boost::make_iterator_range(directory_iterator(p), {})){
            std::cout << entry.path().string() << "\n";
			LuvColorHistogram hist;
			hist.load(entry.path().string(), false);
			hist_vector.push_back(hist);
	}

}

void compare_hist_vectors(const vector<LuvColorHistogram>& h1, const vector<LuvColorHistogram>& h2){

	vector<LuvColorHistogram>::const_iterator it1= h1.begin();
	int c1(0);
	for (; it1 != h1.end(); ++it1){
		vector<LuvColorHistogram>::const_iterator it2= h2.begin();
		int c2(0);
		// Fill-in: iterate over h2 and compare it1 and it2
                // For each histogram in h1, find the closest two in h2.
                // Ideally, you should also show the corresponding images, or at least the file-names for quick verification.
		std::cout << (*it1).LuvColorHistogram::compare(*it2) <<std::endl;
		//std::cout << (*it1)._hist.depth() << std::endl;
	}
}

bool pairCompare(const pair<double, string>& firstElem, const pair<double, string>& secondElem) {
  return firstElem.first < secondElem.first;
}

int main(int argc, const char* argv[]) {

	if (argc < 3){
		cerr<< "Usage: \n"<< argv[0]<< " [folder name train] [folder name test]"<< endl;
		return -1;
	}

	path p (argv[1]);
	if (!verify_folder(p)) return -1;

	path q (argv[2]);
	if (!verify_folder(q)) return -1;


	vector<LuvColorHistogram> histogram_train;
	vector<LuvColorHistogram> histogram_test;

	load(p, histogram_train);
	load(q, histogram_test);
	cout<< "*** loaded "<< histogram_train.size()<< " train samples."<< endl;
	cout<< "*** loaded "<< histogram_test.size()<< " test samples."<<endl;

	cout<< "Comparing histograms"<< endl;
	compare_hist_vectors(histogram_train, histogram_test);

	cout<< endl<< endl;


}
