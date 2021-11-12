class	CrapTrap
{
	public:
		CrapTrap();
		CrapTrap( const CrapTrap& original );
		~CrapTrap();
		Fixed&		operator= ( const Fixed& right );
		void		attack( std::string const & target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
		std::string	getName( void );
		int			getHitPoints( void );
		int			getEnergyPoints( void );
		int			getAttackDamage( void );
		void		getName( std::string name );
		void		getHitPoints( int );
		void		getEnergyPoints( int );
		void		getAttackDamage( int );
	private:
		std::string	_Name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
};
