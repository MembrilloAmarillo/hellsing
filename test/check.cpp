size_t my_strlen( char const* buffer )
{
  assert( buffer != nullptr );
  size_t i = 0;

  do {
    i++;
  } while ( *(buffer + i) != '\0' );

  return i;
}

int my_strcmp( const char* str1, const char* str2 ) {
  int idx = 0;
  int diff = (int)( my_strlen( str1 ) - my_strlen( str2 ) );

  do {
    if ( ( *( str1 + idx ) == '\0' ) && ( *( str2 + idx ) != '\0' ) ) {
      return diff;
    } else if ( ( *( str1 + idx ) != '\0' ) && ( *( str2 + idx ) == '\0' ) ) {
      return diff; 
    }else if ( *( str1 + idx ) != *( str2 + idx ) ) {
      return -1;
    }else {
		// equal
    }
    idx++;
  } while ( *( str1 + idx ) != '\0' && *( str2 + idx ) != '\0' );

    return 0;
}