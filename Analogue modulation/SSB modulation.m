%%%%%%%%%%%%%%%%%%%%%% Single Side Band %%%%%%%%%%%%%%%%%%%%%%
% Shereen Mostafa Mabrouk  6844     GROUP 3 SECTION 2
% Youssef Ahmed AbouEid    6883     GROUP 3 SECTION 2
% Omar Walied Mohamed      7058     GROUP 3 SECTION 2
% Habiba Mohamed Hefny     6939     GROUP 3 SECTION 2
% Hend Khaled Abdelhamid      6986     GROUP 3 SECTION 2

clc;clear;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%[file,path] =  uigetfile();
%filename=fullfile(path,file);
% first of all lets select the sound we want
% the given audio file is eric.wav
[msound,FS]=audioread('eric.wav');
sound(msound, FS);
pause(10);
% getting the length of the sound to use it in plotting
Length_of_sound=length(msound);
Length_of_sound_distribution=length(msound)/FS;
% time for x axis
time=(linspace(0,Length_of_sound_distribution,Length_of_sound));

%plot the signal sound in time domain
subplot(2,2,1)
plot(time,msound)
title('Original Signal in time domain'); 
xlabel('Time');ylabel('Amplitude')
%%%%% Plot the original signal at frequancy domain
% x axis 
freq=FS/2*linspace(-1,1,Length_of_sound);
%numel--> return length 
% y axis of frequancy domain
Freq_y=fftshift(fft(msound,numel(freq)));

subplot(2,2,2)
plot(freq,abs(Freq_y))
title('original signal in frequancy domain');
xlabel('Freq (Hz)');ylabel('Amplitude');  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q2&3%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
subplot(2,2,4);plot(freq,abs(sound_filtered_freq));
title('filtered signal in Frequency domain');
xlabel('Freq (Hz)');ylabel('Amplitude');
sound(real(double(sound_filtered)), FS);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q4%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%DSBSC
Fc = 100000;
m = 0.5 ; %modulation index
fs = Fc*5;
signal_resampled = resample(sound_filtered, fs, FS);
%resampling after increasing the sampling frequency
time = linspace(0, length(signal_resampled)/fs, length(signal_resampled));
carrierSignal = cos(2*pi*Fc*time);
carrierSignal=permute(carrierSignal, [2,1]);

%DSB-SC ploting
DSBSC =  signal_resampled.* carrierSignal;
figure(2);
plot(time, DSBSC);                             
title('DSB-SC signal in time domain');
xlabel('time');ylabel('amplitude');
fsc = (-fs/2 : fs/length(DSBSC) : fs/2-fs/length(DSBSC));
figure(3);
plot(fsc, abs(fftshift(fft(DSBSC))));                             
title('DSB-SC signal in freq domain');
xlabel('freq');ylabel('amplitude');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%SSB-SC
ssb_t=imag(hilbert(signal_resampled));
carrier_imag=imag(hilbert(carrierSignal));
SSBsc_timedomain=signal_resampled.* carrierSignal+ssb_t.*carrier_imag;
SSBsc_freqdomain=fftshift( abs(fft(SSBsc_timedomain)));
figure(4);
plot(time,SSBsc_timedomain);title('SSB-SC LSB Time Domain');
figure(5);
plot(fsc,SSBsc_freqdomain);title('SSB-SC LSB Spectrum');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q6%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

demodulation_SSBsc_timedomain=SSBsc_timedomain.*carrierSignal;
demodulation_SSBsc_freqdomain=fftshift(abs(fft(demodulation_SSBsc_timedomain)));
cutoff_freq=Fc/((fs/2));
[zeros,poles]=butter(20,cutoff_freq,'low');
% y axis of filtered signal
sound_filtered_ssbsc=filter(zeros,poles,demodulation_SSBsc_timedomain);
sound_filtered_ssbsc_freq=fftshift(abs(fft(sound_filtered_ssbsc)));
%
figure(6);
plot(time, sound_filtered_ssbsc);title('SSB-SC Demodulated Signal in Time Domain');
figure(7);
plot(fsc, sound_filtered_ssbsc_freq);title('SSB-SC Demodulated Spectrum');
%resample the output signal and play sound
RESAMPLE_SSBsc = resample(sound_filtered_ssbsc,FS,5*Fc);
sound(RESAMPLE_SSBsc,FS);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q7%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

cutoff_freq=4000/(FS/2);
% the order of butterworth filter is 4
[zeros,poles]=butter(4,cutoff_freq,'low');
SSBsc_butt4=filter(zeros,poles,DSBSC);
SSBsc_butt4_freq=fftshift(abs(fft(SSBsc_butt4)));
figure(8);
plot(time, SSBsc_butt4);
title('SSB-SC time domain using practical Butterworth filter');
figure(9);
plot(fsc, SSBsc_butt4_freq);
title('SSB-SC spectrum using practical Butterworth filter');
% lets do the demodulation 
demodulation_SSBsc_butt4_timedomain=SSBsc_butt4.*carrierSignal;
demodulation_SSBsc_butt4_freqdomain=fftshift(abs(fft(demodulation_SSBsc_butt4_timedomain)));
cutoff_freq=Fc/((fs/2));
[zeros,poles]=butter(4,cutoff_freq,'low');
% y axis of filtered signal
sound_filtered_ssbsc_butt4=filter(zeros,poles,demodulation_SSBsc_butt4_timedomain);
sound_filtered_ssbsc_freq_butt4=fftshift(abs(fft(sound_filtered_ssbsc_butt4)));
figure(10);
plot(time, sound_filtered_ssbsc_butt4);title('SSB-SC Demodulated Signal Butterworth in Time Domain');
figure(11); 
plot(fsc, sound_filtered_ssbsc_freq_butt4);title('SSB-SC Demodulated Butterworth Spectrum');
%resample the output signal and play sound
RESAMPLE_SSBsc_butt = resample(sound_filtered_ssbsc_butt4,FS,5*Fc);

sound(RESAMPLE_SSBsc_butt, FS);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q8%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%noise added to SSB-SC
cutoff_freq=Fc/((fs/2));
[zeros,poles]=butter(20,cutoff_freq,'low');

%noise=0 dB
noise0=awgn(SSBsc_timedomain,0);
noise0 = noise0 .* carrierSignal;
%pass signal through lowpass filter to remove USB
noise0 = filter(zeros,poles,noise0);
noise0_spectrum = fftshift(abs(fft(noise0)));
%plot generated signal and play sound
figure(12);
plot(time, noise0);title('SSB-SC Signal With Guassian Noise of 0 dB in time domain');
figure(13);
plot(fsc, noise0_spectrum);title('SSB-SC Signal With Guassian Noise of 0 dB in frequency domain');
noise0 = resample(noise0,FS,5*Fc);
sound(noise0, FS);
pause(10);

%Noise=10 dB
noise10=awgn(SSBsc_timedomain,10);
noise10 = noise10 .* carrierSignal;
%pass signal through lowpass filter to remove USB
noise10 = filter(zeros,poles,noise10);
noise10_spectrum = fftshift(abs(fft(noise10)));
%plot generated signal and play sound
figure(14);
plot(time, noise10);title('SSB-SC Signal With Guassian Noise of 10 dB in time domain');
figure(15);
plot(fsc, noise0_spectrum);title('SSB-SC Signal With Guassian Noise of 10 dB in frequency domain');
noise10 = resample(noise10,FS,5*Fc);
sound(noise10, FS);
pause(10);

%Noise=30 dB
noise30=awgn(SSBsc_timedomain,10);
noise30 = noise30 .* carrierSignal;
%pass signal through lowpass filter to remove USB
noise30 = filter(zeros,poles,noise30);
noise30_spectrum = fftshift(abs(fft(noise30)));
%plot generated signal and play sound
figure(16);
plot(time, noise30);title('SSB-SC Signal With Guassian Noise of 30 dB in time domain');
figure(17);
plot(fsc, noise0_spectrum);title('SSB-SC Signal With Guassian Noise of 30 dB in frequency domain');
noise30 = resample(noise30,FS,5*Fc);
sound(noise30, FS);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q9%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

carrier_amp = 2 * max(real(sound_filtered));
%double side band transmitted carrier in time domain
DSB_TC_timeDomain = (carrier_amp + signal_resampled) .* carrierSignal;
%double side band transmitted carrier in frequency domain
DSB_TC_freqDomain = fftshift(abs(fft(DSB_TC_timeDomain)));
%plot DSB-TC in time domain and frequency domain
figure(18);
plot(time, DSB_TC_timeDomain); title('DSB-TC in Time Domain');
figure(19);
plot(fsc, DSB_TC_freqDomain); title('DSB-TC spectrum');
%Pass the DSB-TC through a low pass filter to get the original signal
design_filter = designfilt('lowpassfir', 'FilterOrder', 8000, 'CutoffFrequency', Fc, 'SampleRate', 5*Fc);
SSB_TC_timeDomain  = filter(design_filter, DSB_TC_timeDomain);
SSB_TC_freqDomain = fftshift(abs(fft(SSB_TC_timeDomain)));
%plot the generated signal in time domain and frequency domain
figure(20);
plot(time, SSB_TC_timeDomain); title('SSB-TC in Time Domain');
figure(21);
plot(fsc, SSB_TC_freqDomain); title('SSB-TC spectrum');
%Use hilbert transform to create envelope detector for SSB-TC
received_envelope_SSB_TC_timeDomain = abs(hilbert(SSB_TC_timeDomain));
received_envelope_SSB_TC_freqDomain = fftshift(abs(fft(received_envelope_SSB_TC_timeDomain)));
%plot generated signal in time domain and frequency domain
figure(22);
plot(time, received_envelope_SSB_TC_timeDomain);title('Envelope of SSB-TC in time domain');
figure(23);
plot(fsc, received_envelope_SSB_TC_freqDomain);title('Envelope of SSB-TC in frequency domain');
%play sound
received_envelope_SSB_TC_timeDomain = resample(received_envelope_SSB_TC_timeDomain,FS,5*Fc);
sound(received_envelope_SSB_TC_timeDomain, FS);
pause(10);
