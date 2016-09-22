
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "luv_color_histogram.hh"
#include <algorithm>

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

void load(path& p, vector<LuvColorHistogram>& hist_vector, 
			vector<pair<double, string> > &result){
	directory_iterator it(p);
	//directory_iterator end_it;
	for(auto& entry : boost::make_iterator_range(directory_iterator(p), {})){
            std::cout << entry.path().string() << "\n";
			result.push_back(pair<double, string>(0, entry.path().string()));
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

inline bool file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int main(int argc, const char* argv[]) {

	if (argc < 3){
		cerr<< "Usage: \n"<< argv[0]<< " [original image] [folder path test]"<< endl;
		return -1;
	}

	if(!file_exists(argv[1]))
	return -1;

	vector<pair<double, string> > result;
	LuvColorHistogram hist_origin;
	hist_origin.load(argv[1], false);

	path q (argv[2]);
	if (!verify_folder(q)) return -1;


	vector<LuvColorHistogram> histogram_train;
	load(q, histogram_train, result);

	cout<< "Comparing histograms"<< endl;
	//compare_hist_vectors(histogram_train, histogram_test);
	
	for(int i = 0; i < histogram_train.size(); i++){
		result[i].first = hist_origin.compare(histogram_train[i]);
	}
	sort(result.begin(), result.end(), pairCompare);
	cv::Mat orig_img = cv::imread(argv[1]);
	cv::imshow("Origin image", orig_img);
	cv::Mat img1 = cv::imread(result[0].second);
	cv::imshow("First match", img1);
	cout << result[0].second << endl;
	cv::Mat img2 = cv::imread(result[1].second);
	cv::imshow("Second match", img2);
	cout << result[1].second << endl;
	cv::waitKey(0);
	return 0;
}
