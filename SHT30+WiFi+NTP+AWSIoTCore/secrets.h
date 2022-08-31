#include <pgmspace.h>

#define SECRET

const char SECRET_SSID[] = "AP";
const char SECRET_PSW[] = "lavit2ap_";

// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAMW66KQc/C4Jz6RbIg1ag3dH3OaGMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA4MzAxMTE0
MjhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDPY5SfphFHDl7vE0kM
wqthcVh/lUIN3nI0Dcewbgi/oI0DeoJZKoJx66lHhsQXgZnAtx7Bop3n34Rikokx
57UkFQj0kBV3+ztz8V/AV04bMtBd86f9/IS3wflNDrv648b3an662B+HmRdRcA+q
kFL5FoUkTBsqBHgCUOyvVCHILq3I+2vZjWsl/fcaZNTq0sdlrs6IEaRdrJA0+H/V
MuFl+CwQQKSfPUZYclfckeLUmyuPq1nkwnn5hNGTHIKOLfRpKV9jaaBTIiQOYZL1
0bz0vevhttdYB9QFVoKs2ZVuWGQcJBx3fTXHO+4VvUaF30rNrq/Q9mDtbn6vtfGZ
OLdjAgMBAAGjYDBeMB8GA1UdIwQYMBaAFAgik3YsVngsVp8sedAx8WD9zHaNMB0G
A1UdDgQWBBQ65WZ2XUg2tI3D2I7+CEYm8irjATAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAARg1j9knv9vyka2Jep9f4Qu1
ChMDzuORdLI9HXht40Xelzo5y7pI2gnmUXGCFmetFQDWSsM20Dg8FoH7r/EUg0tB
07kx7ZAiUCGh7a98efc4rv1+CA5WrO507U9WKp2Ky3BzLF4gdszucZb9frCREZlW
ZgrZliZ4YMkyYR6sO6D3OQZAQxNnxP8mqvyYSti+LY1MXf9y5sEvWIISC1epXYXM
vRlRHXX8lXXrILFCdfcra8HCHimH85jtwTlorS8rHkaN99plDxNejTEIRyVsiDt2
9W+/imKfy1/tlpgZhxGQIIc7M1hN+ujzEmZJQvArO5yoaLUq4HMpj9w81KqkkA==
-----END CERTIFICATE-----


)KEY";
 
 
// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAz2OUn6YRRw5e7xNJDMKrYXFYf5VCDd5yNA3HsG4Iv6CNA3qC
WSqCceupR4bEF4GZwLcewaKd59+EYpKJMee1JBUI9JAVd/s7c/FfwFdOGzLQXfOn
/fyEt8H5TQ67+uPG92p+utgfh5kXUXAPqpBS+RaFJEwbKgR4AlDsr1QhyC6tyPtr
2Y1rJf33GmTU6tLHZa7OiBGkXayQNPh/1TLhZfgsEECknz1GWHJX3JHi1Jsrj6tZ
5MJ5+YTRkxyCji30aSlfY2mgUyIkDmGS9dG89L3r4bbXWAfUBVaCrNmVblhkHCQc
d301xzvuFb1Ghd9Kza6v0PZg7W5+r7XxmTi3YwIDAQABAoIBAQDMEphINNjhi+Gc
7eQ/GzwbSbak7NGv5gmI8VpjYRNYxXqdRqsHZM4xnYzYpmNFIjGSsl8geY1agta5
TKqWIgRcOhqy1SlbBCvvnj/ze7WPDAR/vui7BAXw8H4J9orBievawL9tyofUHbAV
Yej4lMYg96kSG5XLVdRlqw4MRQRs/sMiTh/H+4Z9eUgjbVhs60CGRwHK1RVSHeHI
BweWI15dtS/hQ1mraTYBM5BGyABW+7TJsigmd73XmUq1rLVFwDZ66iN0f/RvZwtL
u5Vh5c8iqRp+QP1//eiUBuLWybFsEKTduy1OJgRzTgpXjAfuIhuFnMgVF11B/+A9
hcdz6gLJAoGBAPheEd4Suw8fUqCagp10sgWJB+9KPv2fQ4sgvMgCdk7YlZgVN2Bl
Cecq7G7vOAAXSjnLaYBj6ooB7jNsjDJ6LpdKOSh4znmqt52ZC8tUunBPqHQcSLP/
Ub0I7rlay90NK2tmfUbZBdWNMtlBd7ydtmQT0p5CdIL6+u78rBc87cN9AoGBANXD
IRbSNJxi5L+wYhaVZfh9i12tFM4mYARcYwDhXG3WJZwKjX8YMmvgCnOF10RoyS7A
RZsEqix9yFEafIAZ8jUVDzE9wdDbJIJn/E2RZe0vMhWny3M5arEMkGiXx1pg+A9g
/YoxqhH1nMAgQvPaTCtPpFn83cV4/axQrIm94ZxfAoGAbqQhW4eGkz8F5QvPwer5
XyPjSAMQOpWXVkQ4NPV71LYBNiXFbIi2N6fUebrRfKDjbQmjrxFTqzUe8wOZFOd/
F+B1xATFHkgh0fAa4/KTt3KU/VyYOq8zr31qM2IyTQAP5qFaj5QgWDi1fTj/6SNs
2/pEqkG6e5ro7EvdMeDvnlUCgYAzHTixU0xfRMp8B7o8ujaq56JGoReDf+ufv1Ox
JzJJ1VYi7OcOyANuhiEZpJxn8EKDGljKi6ABiYY31oSEwS+If+OlG6ZXwb8GK8VJ
6wWbZJiuUvQ0NjuL4Hw7dmel9d/7FW8q91s6dieoTU6VLtLd3GppVizVhmvqI1RO
j4f+MwKBgBROrkvUvDtG5WRWZwkeI7WTwb2ZKShv6cxfhrSHx7p49I6fFqtmaFF4
2AiTBVvl2r3/YzAQFw5NTHXKYBo0katlWrlIezMnJrpyh/uhYB7irLyyGN4SXrWJ
+yEzXDTeHfou+bhxjSEcjqc6rO/lQ8U+KqySjG/r1uoWPXjgHXTv
-----END RSA PRIVATE KEY-----



)KEY";


// Copy contents from AmazonRootCA1.pem
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5 
-----END CERTIFICATE-----
)EOF";