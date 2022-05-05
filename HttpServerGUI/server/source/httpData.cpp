#include "server/source/httpData.h"
#include "server/source/httpRequest.h"
#include "server/source/httpResponse.h"

HttpData::HttpData(HttpRequest *request, HttpResponse *response) : request(request), response(response), state(), finished(false)
{
}

void HttpData::checkFinished()
{
    if (finished)
        throw HttpException(HttpStatus::None);
}

HttpData::~HttpData()
{
    delete request;
    delete response;
}
