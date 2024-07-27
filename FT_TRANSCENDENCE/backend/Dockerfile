FROM alpine:latest

RUN apk update && \
    apk upgrade && \
    apk add postgresql && \
    apk add gcc && \
    apk add python3 && \
    apk add python3-dev && \
    apk add musl-dev && \
    apk add libffi-dev && \
    apk add openssl && \
    apk add openrc && \
    apk add redis

RUN mkdir /backend; \
    chmod +rwx /backend
WORKDIR /backend
COPY . .

COPY clearLaunch.sh /clearLaunch.sh
RUN chmod +x /clearLaunch.sh

EXPOSE 8000

CMD ["sh", "/clearLaunch.sh"]
