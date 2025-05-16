FROM ubuntu:bionic

WORKDIR /home/etsi-its-asn1

RUN apt update
RUN apt install -y git build-essential automake libtool wget sed

RUN git -C /home/etsi-its-asn1 clone https://github.com/brchiu/asn1c.git -n asn1c
RUN git -C /home/etsi-its-asn1/asn1c checkout velichkov_s1ap_plus_option_group_plus_adding_trailing_ull
RUN git -C /home/etsi-its-asn1/asn1c status -v

RUN ( cd /home/etsi-its-asn1/asn1c ; autoreconf -iv ; ./configure --prefix=/usr )
RUN make -C /home/etsi-its-asn1/asn1c
RUN make -C /home/etsi-its-asn1/asn1c install
RUN rm -rf /home/etsi-its-asn1/asn1c

WORKDIR /home/etsi-its-asn1

CMD ./syntax_check.bash
