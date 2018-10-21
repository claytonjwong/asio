#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std; // For time_t, time and ctime;
    time_t now = time( 0 );
    return ctime( &now );
}

int main( )
{
    try
    {
        boost::asio::io_context ioContext;

        tcp::acceptor acceptor( ioContext, tcp::endpoint(tcp::v4(), 6969) );

        for( ;; )
        {
            tcp::socket socket( ioContext );
            acceptor.accept( socket );

            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            boost::asio::write( socket, boost::asio::buffer(message), ignored_error );
        }
    }
    catch( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
