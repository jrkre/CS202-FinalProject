#include "Processor.h"


Wav Processor::echo(Wav &input, double seconds, float gain)
{
    int delay = seconds * input.getHeader().sample_rate;
	auto audio = input.getBuffer();
	std::vector<float> output;

	for (int i = startOfFile; i < input.getDataBytes(); i++)
    {
		if (i > delay) 
		{
			output.push_back(audio[i] + gain*output[i - delay]);
		}
		else 
		{
			output.push_back(audio[i]);
		}
    }
    
	return Wav(input, output);
}

Wav Processor::normalization(Wav &input)
{
    auto audio = input.getBuffer();

    float max = 0;
    float min = 0;

    for (int i = startOfFile; i < input.getDataBytes(); i++)
    {
        if (audio[i] < min)
        {
            min = (float) audio[i];
        }
        else if (audio[i] > max)
        {
            max = (float) audio[i];
        }
    }

    float scaleFactor = (255 / max);

    for (int i = startOfFile; i < input.getDataBytes(); i++)
    {
        //std::cout << (int)audio[i] << " ";
        audio[i] = audio[i] * scaleFactor;
        //std::cout << (int)audio [i] << std::endl;
    }

    //std::cout << "min: " << min << " max: " << max <<std::endl;


    return Wav(input, audio);
}

Wav Processor::gainAdjust(Wav &input, double scaleFactor)
{
    auto audio = input.getBuffer();


    for (int i = startOfFile; i < input.getDataBytes(); i++)
    {
        audio[i] = audio[i] * scaleFactor;
    }
    return Wav(input, audio);
}
