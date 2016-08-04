#include <iostream>
#include <vector>
#include <string>

using namespace std ;

typedef  string  Name ;
typedef  string  Location ;

// �T�����O
class  Car {
  protected :
    // ���ȤH��
    int  passenger_no ;                   
    // �غc�禡
    Car( int n = 0 )  : passenger_no(n) {}
  public :
    // ���w�����B��l�P�C�L�����禡
    virtual Car&  operator=( const Car& foo ) = 0 ;
    virtual ostream&  print( ostream& out ) const = 0 ;
    // ���ȼƥ�
    int  passenger() const {  return passenger_no ;  }
    // �����Ѻc�禡
    virtual ~Car() {}

} ;

// �и���X�B��l
ostream&  operator<< ( ostream& out , const Car& foo ) {
    return  foo.print(out) ;
}

// ��Ȩ����O 
class  RV :  public  Car {
  private :
    Location   place ;   // ���ɳB��
  public :
    // �غc�禡
    RV( Location p , int no = 0 ) : Car(no) , place(p) {}
    // ���w�غc�禡
    RV&  operator= ( const RV& foo ) {
        place        = foo.place ;
        passenger_no = foo.passenger_no ;
        return  *this ;
    }
    // ���w�غc�禡
    RV&  operator= ( const Car& foo ) {
        return  operator=( dynamic_cast<const RV&>(foo) ) ;
    }
    // �C�L
    ostream&  print( ostream& out ) const {
        return  out << "> ��Ȩ�   \t"
                    << "  ����   : " << passenger_no << " �H\t\t" 
                    << "  �ȹC�a : " << place ;
    }
} ;

// ����§�����O
class  Limousine : public  Car {
  private :
    Name   driver ;      // �q��
  public :
    // �غc�禡
    Limousine( Name d , int no = 0 ) : Car(no) , driver(d) {}
    // ���w�غc�禡 : �t�@�سB�z�覡
    Limousine&  operator= ( const Car& car ) {
        const Limousine  *lm = 
            dynamic_cast<const Limousine*>(&car) ;
        if ( lm ) {
            driver = lm->driver ;
            passenger_no = lm->Car::passenger_no ;
        }
        return *this ;
    }

    // �C�L
    ostream&  print( ostream& out ) const {
        return  out << "> ����§�� \t" 
                    << "  ����   : " << passenger_no << " �H\t\t" 
                    << "  �q��   : " << driver ;
    }
};

// �Ҧ������y RV �������`��
int  total_RV_passengers( const vector<Car*>& foo ) {
    RV*  rv ;
    int  no = 0 ;
    // �ˬd�}�C, �Y�����V RV, �h�N��H�ƥ[�J
    for ( int i = 0 ; i < foo.size() ; ++i ) {
        rv = dynamic_cast<RV*>(foo[i]) ;
        if ( rv ) no += rv->passenger() ;
    }
    return  no ;

}

// �N�}�C���Ҧ��� RV ��ƭ��s�]�w
void  setup_RV_data( vector<Car*>&  foo , Location  place ) {
    Car  *new_rv = new RV(place) ;
    // �N�O RV ����ƨ��X, ���s�]�w
    for ( int i = 0 ; i < foo.size() ; ++i ) *foo[i] = *new_rv ;
    delete  new_rv ;
    
}

int main() {

    int  i ;
    
    // ���ЦV�q�}�C
    vector<Car*>  cars ;     

    cars.push_back( new RV("�Ὤ",5) ) ;
    cars.push_back( new Limousine("�i�T",4) ) ;
    cars.push_back( new RV("���B",5) ) ;
    cars.push_back( new RV("�H��",3) ) ;
    cars.push_back( new Limousine("���|",8) ) ;
    
    // �C�L�Ҧ��T�����
    for ( i = 0 ; i < cars.size() ; ++i ) 
        cout << *cars[i] << endl ;

    // �C�L RV �`���ȤH��
    cout << "> RV �`���ȤH�� : " << total_RV_passengers(cars) 
         << "\n\n" ;

    // ���s�]�w RV ���, �P�C�L
    setup_RV_data( cars , "" ) ;
    for ( i = 0 ; i < cars.size() ; ++i ) 
        cout << *cars[i] << endl ;
    
    // �M���Ҧ��ʺA���
    for ( i = 0 ; i < cars.size() ; ++i ) delete  cars[i] ;

    return 0 ;
    
}