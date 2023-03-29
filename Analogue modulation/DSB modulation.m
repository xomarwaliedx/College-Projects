%%%%%%%%%%%%%%%%%%%%%% Double Side Band %%%%%%%%%%%%%%%%%%%%%%
% Omar Walied Mohamed      7058     GROUP 3 SECTION 2
% Habiba Mohamed Hefny     6939     GROUP 3 SECTION 2
% Shereen Mostafa Mabrouk  6844     GROUP 3 SECTION 2
% Youssef Ahmed AbouEid    6883     GROUP 3 SECTION 2
% Hend Khaled Abdelhamid   6986     GROUP 3 SECTION 2
clc;clear;

% the following three lines are for any audio file
%[file,path] =  uigetfile();
%filename=fullfile(path,file);
% first of all lets select the sound we want
% the given audio file is eric.wav
%reading attached audio file
[mysound, Fm] = audioread("eric.wav");

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mysound_length=length(mysound);
mysound_length_dis=length(mysound)/Fm;
time=(linspace(0,mysound_length_dis,mysound_length));
subplot(2,2,1)
plot(time,mysound); title('original signal in time domain');

%frequency spacing within signal
freq_shift = (-mysound_length / 2:mysound_length / 2 - 1) * (Fm / mysound_length);
%transfer mysound from time to frequency domain
mysound_Frequency_domain = fftshift(abs(fft(mysound)));
subplot(2,2,2)
plot(freq_shift, mysound_Frequency_domain); title('original signal in frequency domain');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q2 & Q3%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%using filter to remove frequencies greater than 4kHz

mysound_filtered_t = resample(mysound,48000,Fm);
mysound_filtered_t=lowpass(mysound_filtered_t,4000,48000);

%ploting filtered signal in time domain
mysound_filtered_t_length = length(mysound_filtered_t);
mysound_filtered_t_dis = mysound_filtered_t_length / (Fm);
t = linspace(0, mysound_filtered_t_dis, mysound_filtered_t_length);
subplot(2,2,3)
plot(t, mysound_filtered_t); title('Signal filtered in time(BW=4K)');

%ploting filtered signal in frequency domain
mysound_filtered_f=fftshift(abs(fft(mysound_filtered_t)));
mysound_filtered_t_length = length(mysound_filtered_t);
freq_shift = (-mysound_filtered_t_length / 2:mysound_filtered_t_length / 2 - 1) * (Fm / mysound_filtered_t_length);
subplot(2,2,4)
plot(freq_shift, mysound_filtered_f); title('Signal filtered in freq domain(BW=4K)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q4%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sound(mysound_filtered_t, Fm);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A) DSB-SC modulation 
%carrier frequency 
fc=100000;
%resampling filtered audio to have freq=5*carrier freq
mysound_filtered_t_r = resample(mysound_filtered_t, 5 * fc, Fm);
new_mysound_length_r = length(mysound_filtered_t_r);
new_mysound_dis = new_mysound_length_r / (5 * fc);
t = linspace(0, new_mysound_dis, new_mysound_length_r);

%carrier signal
ct = cos(2 * pi * fc * t)';
%DSB-SC in time domain
DSB_SC_t = mysound_filtered_t_r .* ct;
figure(2);
plot(t, abs(DSB_SC_t)); title('DSB-SC in time domain');

%DSB-SC in frequency domain
DSB_SC_f = fftshift(abs(fft(DSB_SC_t)));
DSB_SC_f_length = length(DSB_SC_f);
new_freq_shift = (-DSB_SC_f_length / 2:DSB_SC_f_length / 2 - 1) * ((5 * fc) / DSB_SC_f_length);
figure(3);
plot(new_freq_shift, abs(DSB_SC_f)); title('DSB-SC spectrum');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% B) DSB-TC modulation 
%DSB-TC in time domain
Am=max(mysound_filtered_t_r);
DSB_TC_t=(1+(0.5/Am).*mysound_filtered_t_r).*ct;
figure(4);
plot(t, abs(DSB_TC_t));  title('DSB-TC in time domain');
%DSB-TC in frequency domain
DSB_TC_f = fftshift(abs(fft(DSB_TC_t)));
DSB_TC_f_length = length(DSB_TC_f);
new_freq_shift = (-DSB_TC_f_length / 2:DSB_TC_f_length / 2 - 1) * ((5 * fc) / DSB_TC_f_length);
figure(5);
plot(new_freq_shift, abs(DSB_TC_f)); title('DSB-TC spectrum');

%%%%%%%%%%%%%%%%%%%%%%%%%Demodulation using Envelop Detector%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%DSB-SC
envelope_DSB_SC=abs(hilbert(DSB_SC_t));
envelope_DSB_SC = resample(envelope_DSB_SC, Fm, 5 * fc);
%length of resampled signal
envelope_sound_SC_length = length(envelope_DSB_SC);
t_envelope_sc = linspace(0, (5 * fc), envelope_sound_SC_length);
%plotting the envelope of the DSB-SC
figure(6);
plot(t_envelope_sc, envelope_DSB_SC); title('envelope of the DSB-SC');
%Note that the sound quality has significantly dropped 
%envelope detector should not be used with supressed carrier 
sound(envelope_DSB_SC, Fm);
pause(10);

%%%%%%%%DSB-TC
envelope_DSB_TC=abs(hilbert(DSB_TC_t));
envelope_DSB_TC = resample(envelope_DSB_TC, Fm, 5 * fc);

%length of resampled signal
envelope_sound_TC_length = length(envelope_DSB_TC);
t_envelope_TC = linspace(0, (5 * fc), envelope_sound_TC_length);

%plotting the envelope of the DSB-TC
figure(7);
plot(t_envelope_TC, envelope_DSB_TC); title('envelope of the DSB-TC');

sound(envelope_DSB_TC, Fm);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Coherent Detection%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%DSB-SC

%%%SNR=0
noisezero=awgn(DSB_SC_t,0,"measured");

demodulated_DSB_SC_t=noisezero.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);

figure(8);
plot(t, demodulated_DSB_SC_t); title('Demodulated DSB-SC signal with SNR=0 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(9);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); title('Demodulated DSB-SC signal with SNR=0 in frequency domain');

%%%SNR=10dB
noise10=awgn(DSB_SC_t,10,"measured");
demodulated_DSB_SC_t=noise10.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(10);
plot(t, demodulated_DSB_SC_t); title('Demodulated DSB-SC signal with SNR=10 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(11);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); title('Demodulated DSB-SC signal with SNR=10 in frequency domain');


%%%SNR=30dB
noise30=awgn(DSB_SC_t,30,"measured");

demodulated_DSB_SC_t=noise30.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);

figure(12);
plot(t, demodulated_DSB_SC_t); title('Demodulated DSB-SC signal with SNR=30dB in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(13);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); title('Demodulated DSB-SC signal with SNR=30dB in frequency domain');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Coherent Detection%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%DSB-TC

%SNR=0
noisezero=awgn(DSB_TC_t,0,"measured");
demodulated_DSB_TC_t=noisezero.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(14);
plot(t, demodulated_DSB_TC_t); title('Demodulated DSB-TC signal with SNR=0 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%SNR=10dB
noise10=awgn(DSB_TC_t,10,"measured");
demodulated_DSB_TC_t=noise10.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(15);
plot(t, demodulated_DSB_TC_t); title('Demodulated DSB-TC signal with SNR=10 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%coherent detector in frequency domain
demodulated_DSB_TC_f = fftshift(abs(fft(demodulated_DSB_TC_t)));
demodulated_DSB_TC_f_length = length(demodulated_DSB_TC_f);
new_freq_shift = (-demodulated_DSB_TC_f_length / 2:demodulated_DSB_TC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_TC_f_length);

figure(16);
plot(new_freq_shift, abs(demodulated_DSB_TC_f)); title('Demodulated DSB-TC signal with SNR=10 in frequency domain');


%SNR=30
noise30=awgn(DSB_TC_t,30,"measured");

demodulated_DSB_TC_t=noise30.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(17);
plot(t, demodulated_DSB_TC_t); title('Demodulated DSB-TC signal with SNR=30 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q9%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%frequency error
DSB_SC_t_length = length(DSB_SC_t);
DSB_SC_t_dis = DSB_SC_t_length / (5 * fc);
t = linspace(0, DSB_SC_t_dis, DSB_SC_t_length);

%carrier signal
fc_error=100100;
ct_frequency_error = cos(2 * pi * fc_error * t);

%%%%%%%%%%DSB_SC

%SNR=0
noisezero=awgn(DSB_SC_t,0,"measured");
demodulated_DSB_SC_t=noisezero.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(18);
plot(t, demodulated_DSB_SC_t);
title('frequency error - DSB-SC Demodulated signal with SNR=0 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%Frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift =(-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(19);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('frequency error - DSB-SC Demodulated signal with SNR=0 in frequency domain');


%SNR=10dB
noise10=awgn(DSB_SC_t,10,"measured");
demodulated_DSB_SC_t=noise10.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(20);
plot(t, demodulated_DSB_SC_t); 
title('frequency error - DSB-SC Demodulated signal with SNR=10 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%Frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(21);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('frequency error- supressed carrier Demodulated signal with SNR=10dB in frequency domain');

%SNR=30dB
noise30=awgn(DSB_SC_t,30,"measured");
demodulated_DSB_SC_t=noise30.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(22);
plot(t, demodulated_DSB_SC_t); 
title('frequency error- supressed carrier Demodulated signal with SNR=30dB in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(23);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('frequency error- DSB-SC Demodulated signal with SNR=30dB in frequency domain');


%%%%%%%%%%DSB_TC

%SNR=0
noisezero=awgn(DSB_TC_t,0,"measured");
demodulated_DSB_TC_t=noisezero.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(24);
plot(t, demodulated_DSB_TC_t); 
title('frequency error - DSB-TC Demodulated signal with SNR=0 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%SNR=10dB
noise10=awgn(DSB_TC_t,10,"measured");
demodulated_DSB_TC_t=noise10.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(25);
plot(t, demodulated_DSB_TC_t); 
title('frequency error - DSB-TC Demodulated signal with SNR=10 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_TC_f = fftshift(abs(fft(demodulated_DSB_TC_t)));
demodulated_DSB_TC_f_length = length(demodulated_DSB_TC_f);
new_freq_shift = (-demodulated_DSB_TC_f_length / 2:demodulated_DSB_TC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_TC_f_length);
figure(26);
plot(new_freq_shift, abs(demodulated_DSB_TC_f)); 
title('frequency error - DSB-TC Demodulated signal with SNR=10 in frequency domain');

%SNR=30
noise30=awgn(DSB_TC_t,30,"measured");
demodulated_DSB_TC_t=noise30.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(27);
plot(t, demodulated_DSB_TC_t); 
title('frequency error - DSB-TC Demodulated signal with SNR=30 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Q10%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
%phase error=20

DSB_SC_t_length = length(DSB_SC_t);
DSB_SC_t_dis = DSB_SC_t_length / (5 * fc);
t = linspace(0, DSB_SC_t_dis, DSB_SC_t_length);

%carrier signal
fc=100000;
ct_frequency_error = cos((2 * pi * fc * t)+deg2rad(20));

%%%%%%%%%%%DSB_SC

%SNR=0
noisezero=awgn(DSB_SC_t,0,"measured");
demodulated_DSB_SC_t=noisezero.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(28);
plot(t, demodulated_DSB_SC_t); 
title('phase error - DSB-SC Demodulated signal with SNR=0 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(29);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('phase error - DSB-SC Demodulated signal with SNR=0 in frequency domain');

%SNR=10dB
noise10=awgn(DSB_SC_t,10,"measured");
demodulated_DSB_SC_t=noise10.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(30);
plot(t, demodulated_DSB_SC_t); 
title('phase error - DSB-SC Demodulated signal with SNR=10 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(31);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('phase error - DSB-SC Demodulated signal with SNR=10 in frequency domain');

%SNR=30dB
noise30=awgn(DSB_SC_t,30,"measured");
demodulated_DSB_SC_t=noise30.*ct;
demodulated_DSB_SC_t=resample(demodulated_DSB_SC_t,Fm,5*fc);
demodulated_DSB_SC_t_length = length(demodulated_DSB_SC_t);
demodulated_DSB_SC_t_dis = demodulated_DSB_SC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_SC_t_dis, demodulated_DSB_SC_t_length);
figure(32);
plot(t, demodulated_DSB_SC_t); 
title('phase error - DSB-SC Demodulated signal with SNR=30 in time domain');
sound(demodulated_DSB_SC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_SC_f = fftshift(abs(fft(demodulated_DSB_SC_t)));
demodulated_DSB_SC_f_length = length(demodulated_DSB_SC_f);
new_freq_shift = (-demodulated_DSB_SC_f_length / 2:demodulated_DSB_SC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_SC_f_length);
figure(33);
plot(new_freq_shift, abs(demodulated_DSB_SC_f)); 
title('phase error - DSB-SC Demodulated signal with SNR=30 in frequency domain');

%%%%%%%%%%%DSB_TC

%SNR=0
noisezero=awgn(DSB_TC_t,0,"measured");
demodulated_DSB_TC_t=noisezero.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(34);
plot(t, demodulated_DSB_TC_t); 
title('phase error - DSB-TC Demodulated signal with SNR=0 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%SNR=10
noise10=awgn(DSB_TC_t,10,"measured");
demodulated_DSB_TC_t=noise10.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(35);
plot(t, demodulated_DSB_TC_t); 
title('phase error - DSB-TC Demodulated signal with SNR=10 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);

%frequency domain
demodulated_DSB_TC_f = fftshift(abs(fft(demodulated_DSB_TC_t)));
demodulated_DSB_TC_f_length = length(demodulated_DSB_TC_f);
new_freq_shift = (-demodulated_DSB_TC_f_length / 2:demodulated_DSB_TC_f_length / 2 - 1) * ((5 * fc) / demodulated_DSB_TC_f_length);
figure(36);
plot(new_freq_shift, abs(demodulated_DSB_TC_f)); 
title('phase error - DSB-TC Demodulated signal with SNR=10 in frequency domain');

%SNR=30
noise30=awgn(DSB_TC_t,30,"measured");
demodulated_DSB_TC_t=noise30.*ct;
demodulated_DSB_TC_t=resample(demodulated_DSB_TC_t,Fm,5*fc);
demodulated_DSB_TC_t_length = length(demodulated_DSB_TC_t);
demodulated_DSB_TC_t_dis = demodulated_DSB_TC_t_length / (5 * fc);
t = linspace(0, demodulated_DSB_TC_t_dis, demodulated_DSB_TC_t_length);
figure(37);
plot(t, demodulated_DSB_TC_t); 
title('phase error - DSB-TC Demodulated signal with SNR=30 in time domain');
sound(demodulated_DSB_TC_t, Fm);
pause(10);
