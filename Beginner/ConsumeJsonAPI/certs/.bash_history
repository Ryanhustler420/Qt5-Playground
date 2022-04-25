openssl
openssl req -out blue_ca.pem -new -x509 -nodes
mv privkey.pem blue_privkey.pem
openssl req -out red_ca.pem -new -x509 -nodes
mv privkey.pem red_privkey.pem
ls
ls -a
ll -a
start
start .
openssl genrsa -out blue_local.key 2048
openssl req -key blue_local.key -new -out blue_local.req
openssl x509 -req -in blue_local.req -CA blue_ca.pem -CAkey blue_privkey.pem -CAserial blue_index.txt -out blue_local.pem
openssl genrsa -out red_local.key 2048
openssl req -key red_local.key -new -out red_local.req
openssl x509 -req -in red_local.req -CA red_ca.pem -CAkey red_privkey.pem -CAserial red_index.txt -out red_local.pem
start .
