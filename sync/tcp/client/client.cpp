#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost::asio::ip;

int main( )
{
    try
    {
        boost::asio::io_context ioContext;
        tcp::socket socket( ioContext );
        tcp::endpoint endpoint( address::from_string("127.0.0.1"), 6969 );
        socket.connect( endpoint );

        for( ;; )
        {
            boost::array< char, 128 > buf;
            boost::system::error_code error;

            size_t len = socket.read_some( boost::asio::buffer(buf), error );

            if( error == boost::asio::error::eof )
                break; // Connection closed cleanly by peer.
            else if( error )
                throw boost::system::system_error(error); // Some other error.

            std::cout.write( buf.data(), len );
        }
    }
    catch( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
