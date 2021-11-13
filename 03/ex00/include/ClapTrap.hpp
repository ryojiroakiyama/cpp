class	CrapTrap
{
	public:
		CrapTrap();
		CrapTrap( const CrapTrap& original );
		~CrapTrap();
		ClapTrap&	operator= ( const ClapTrap& right );
		void		attack( std::string const & target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
		std::string	getName( void );
		int			getHitPoints( void );
		int			getEnergyPoints( void );
		int			getAttackDamage( void );
		void		setName( std::string name );
		void		setHitPoints( int );
		void		setEnergyPoints( int );
		void		setAttackDamage( int );
	private:
		std::string	_Name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
};
