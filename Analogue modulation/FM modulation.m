%%%%%%%%%%%%%%%%%%%%%% FM Demodulation %%%%%%%%%%%%%%%%%%%%%%
% Shereen Mostafa Mabrouk     6844     GROUP 3 SECTION 2
% Youssef Ahmed AbouEid       6883     GROUP 3 SECTION 2
% Omar Walied Mohamed         7058     GROUP 3 SECTION 2
% Habiba Mohamed Hefny        6939     GROUP 3 SECTION 2
% Hend Khaled Abdelhamid      6986     GROUP 3 SECTION 2

clc;clear all;

% the following three lines are for any audio file
%[file,path] =  uigetfile();
%filename=fullfile(path,file);
%[msound,FS]=audioread(filename):
% first of all lets select the sound we want
% the given audio file is eric.wav
%%%%%%%1%%%%%%%%
[msound,FS]=audioread('eric.wav');
% lets take the length of the sound to use it in plotting
Length_of_sound=length(msound);
Length_of_sound_distribution=length(msound)/FS;
% time for x axis
time=(linspace(0,Length_of_sound_distribution,Length_of_sound));
%plot the signal sound in time domain
subplot(2,2,1)
plot(time,msound)
title('Original Signal in time domain'); xlabel('Time');ylabel('Amplitude')
%%%%% Plot the original signal at frequancy domain
% x axis 
freq=FS/2*linspace(-1,1,Length_of_sound);
%numel--> return length 
% y axis of frequency domain
Freq_y=fftshift(fft(msound,numel(freq)));
subplot(2,2,2)
plot(freq,abs(Freq_y))
title('original signal in frequancy domain');
xlabel('Freq (Hz)');ylabel('Amplitude');  
%%%%%%%2%%%%%%%%
% By using low pass filter with a frequancy less than 4khz 
%normalized cutoff frequency
cutoff_freq=4000/(FS/2);
% let say that the order of butterworth filter is 20
[zeros,poles]=butter(20,cutoff_freq,'low');
% y axis of filtered signal
sound_filtered=filter(zeros,poles,msound);
subplot(2,2,3);
plot(time,sound_filtered);
title('filtered signal in time domain');
xlabel('Time');ylabel('Amplitude'); 
% frequency domain of filtered signal 
sound_filtered_freq=fftshift(fft(sound_filtered));
subplot(2,2,4);
plot(freq,abs(sound_filtered_freq));
title('filtered signal in Frequency domain');
xlabel('Freq (Hz)');ylabel('Amplitude');
%%%%%%%%%%%%%3%%%%%%%%%%%%%%%%%
% SOUND PLAYED BEFORE FILTER
sound(msound, FS);
pause(10);
% SOUND PLAYED AFTER FILTER
sound(sound_filtered, FS);
pause(10);
%%%%%%%%%%%%%%4%%%%%%%%%%%%%%%%%%%%%%%
%s(t)=A*cos(Wct+phase deviation)
%where phase deviation = Kf*integeration(m(t))
%let say kf=0.02 --> when kf change the output change
%                 -->modulation index small to be narrow band
Fc=100000; Fs=5*Fc; Kf=0.02;
%Fc--> carrier frequency 
%Fs--->Sampling frequency
resampled_signal=resample(sound_filtered,Fs,FS);
% phase deviation : kf*integration(m(t))
phase_deviation = Kf*2*pi*(cumsum(resampled_signal'));
% signal :
time_NBFM = linspace(0,length(resampled_signal)/Fs, length(resampled_signal));
% we can but the value of Amplitude and multiply it with the cosine
NBFM = cos(2*pi*Fc*time_NBFM+phase_deviation);
%plot time
figure(2)
subplot(2,1,1);
plot(time_NBFM, NBFM );
title('NBFM time domain');
%plot frequency
subplot(2,1,2);
freq_NBFM = (-Fs/2 : Fs/length(NBFM ) : Fs/2- Fs/length(NBFM ));
plot(freq_NBFM, abs(fftshift(fft(NBFM ))));
title('NBFM Frequency domain');
%demodulation 
dy=diff(NBFM);
env=abs(hilbert(dy));%%ED for diff signal
env=env - mean(env);%%NBFM 
fmresample=resample(env,FS,Fs);
sound(fmresample,FS);
pause(10);
t=linspace(0, length(fmresample)/ FS, length(fmresample));
figure(3);
plot(t,fmresample);title('NBFM envelope resampled');

