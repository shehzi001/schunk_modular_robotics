#include <iostream>
#include <schunk_sdh/sdh.h>


using namespace std;



class SchunkSdhControlInterface
{

private:
	SDH::cSDH *sdh_;
	std::vector<SDH::cSDH::eAxisState> state_;
	std::string sdhdevicetype_;
	std::string sdhdevicestring_;
	int sdhdevicenum_;
	int baudrate_, id_read_, id_write_;
	double timeout_;


	bool isInitialized_;
	bool isDSAInitialized_;
	bool isError_;
	int DOF_;
	double pi_;

	std::vector<std::string> joint_names_;
	std::vector<int> axes_;
	std::vector<double> targetAngles_; // in degrees
	std::vector<double> velocities_; // in rad/s
	bool hasNewGoal_;
	std::string operationMode_; 

public:
	SchunkSdhControlInterface()
	{
		pi_ = 3.1415926;
		isError_ = false;
	}

	~SchunkSdhControlInterface()
	{
		if(isInitialized_)
				sdh_->Close();
			delete sdh_;
	}

	bool init()
		{
			// initialize member variables
			isInitialized_ = false;
			isDSAInitialized_ = false;
			hasNewGoal_ = false;

			// pointer to sdh
			sdh_ = new SDH::cSDH(false, false, 0); //(_use_radians=false, bool _use_fahrenheit=false, int _debug_level=0)

			// setting hardware parameters
			sdhdevicetype_ = std::string("PCAN");
			sdhdevicestring_ = std::string("/dev/pcan0");
			sdhdevicenum_ = 0;
			baudrate_ = 1000000;
			timeout_ = (double)0.04;
			id_read_ = 43;
			id_write_ = 42;
			DOF_ = 7;
			
			// define axes to send to sdh
			axes_.resize(DOF_);

			for(int i = 0; i < DOF_; i++)
			{
				axes_[i] = i;
			}
			
			state_.resize(axes_.size());

			operationMode_ = std::string("position");

                        if(sdhdevicetype_.compare("PCAN")==0)
			{
			    cout << "Starting initializing PEAKCAN" << endl;
			    sdh_->OpenCAN_PEAK(baudrate_, timeout_, id_read_, id_write_, sdhdevicestring_.c_str());
			    cout << "Initialized PEAK CAN for SDH" << endl;
			    isInitialized_ = true;
			}
                        
			return true;
		}


};

int main(int argc, char** argv)
{
    
    cout << "schunk sdh control interface running" << endl;

    SchunkSdhControlInterface sdh_interface;
    
    if (!sdh_interface.init()) return 0;

    while(1);

    return 0;
}
